#include "assert.h"
#include "linalg.h"
#include "tensor.h"

struct Tensor		*solve(struct Tensor *lhs, struct Tensor *rhs) {
	struct Tensor	*trans, *solution;
	__assert_tensor_is_vector(rhs);
	__assert_tensor_has_dim(lhs, TENSOR_NUMEL(rhs));
	trans = transpose(lhs);
	solution = linear_combination(inverse_(trans), rhs);
	tensor_free(trans);
	return (solution);
}
