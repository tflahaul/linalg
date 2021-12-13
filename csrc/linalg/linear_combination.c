#include "assert.h"
#include "tensor.h"

static inline void	__ops_linear_cpu(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t i = 0; i < a->shape[0]; i++)
		for (uint32_t j = 0; j < a->shape[1]; j++)
			dst->data[j] += (a->data[(i * a->shape[1]) + j] * b->data[i]);
}

struct Tensor		*linear_combination(struct Tensor *lhs, struct Tensor *rhs) {
	__assert_tensor_has_dim(lhs, rhs->shape[1]);
	struct Tensor	*out = tensor_init_constant(1, lhs->shape[1], 0.);
	__ops_linear_cpu(out, lhs, rhs);
	return (out);
}
