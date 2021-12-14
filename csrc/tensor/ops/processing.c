#include "tensor.h"
#include "linalg.h"
#include "ops.h"

#include <math.h>

struct Tensor		*sdpa(struct Tensor *q, struct Tensor *k, struct Tensor *v) {
	struct Tensor	*a, *b;
	a = softmax_(scl_(mm(q, k), (1. / sqrtf(k->shape[1]))));
	b = mm(a, v); // should be in-place
	tensor_free(a);
	return (b);
}
