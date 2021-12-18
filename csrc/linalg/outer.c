#include "assert.h"
#include "tensor.h"

static inline void	__ops_outer_cpu(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t i = 0; i < dst->shape[0]; i++)
		for (uint32_t j = 0; j < dst->shape[1]; j++)
			dst->data[i * dst->shape[1] + j] = (a->data[i] * b->data[j]);
}

struct Tensor		*outer(struct Tensor *lhs, struct Tensor *rhs) {
	struct Tensor	*out;
	__assert_tensor_is_vector(lhs);
	__assert_tensor_is_vector(rhs);
	out = tensor_init(lhs->shape[1], rhs->shape[1]);
	__ops_outer_cpu(out, lhs, rhs);
	return (out);
}
