#include "tensor.h"
#include "linalg.h"
#include "ops.h"

#include <math.h> // sqrtf

struct Tensor		*sdpa(struct Tensor *q, struct Tensor *k, struct Tensor *v) {
	struct Tensor	*out, *attn;
	attn = softmax_(scl_(mm(q, k), (1.0 / sqrtf(k->shape[1]))));
	out = mm(attn, v);
	tensor_free(attn);
	return (out);
}
