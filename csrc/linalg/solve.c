#include "assert.h"
#include "linalg.h"
#include "tensor.h"

struct Tensor		*solve(struct Tensor *a, struct Tensor *b) {
	struct Tensor	*at, *solution;
	__assert_tensor_is_vector(b);
	__assert_tensor_has_dim(a, TENSOR_NUMEL(b));
	at = transpose(a);
	solution = mm(inverse_(at), b);
	tensor_free(at);
	return (solution);
}
