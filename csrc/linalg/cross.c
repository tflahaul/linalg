#include "assert.h"
#include "tensor.h"

static inline void	__ops_cpu_cross(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t i = 0; i < a->shape[0]; i++) {
		dst->data[i * 3 + 0] = (a->data[i * 3 + 1] * b->data[i * 3 + 2]) - (a->data[i * 3 + 2] * b->data[i * 3 + 1]);
		dst->data[i * 3 + 1] = (a->data[i * 3 + 2] * b->data[i * 3 + 0]) - (a->data[i * 3 + 0] * b->data[i * 3 + 2]);
		dst->data[i * 3 + 2] = (a->data[i * 3 + 0] * b->data[i * 3 + 1]) - (a->data[i * 3 + 1] * b->data[i * 3 + 0]);
	}
}

struct Tensor		*cross(struct Tensor *lhs, struct Tensor *rhs) {
	struct Tensor	*out;
	assert_tensor_has_dim(lhs, 3);
	assert_tensor_broadcastable(lhs, rhs);
	if ((out = tensor_init(lhs->shape[0], 3)) == NULL)
		return (NULL);
	__ops_cpu_cross(out, lhs, rhs);
	return (out);
}
