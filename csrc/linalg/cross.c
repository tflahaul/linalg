#include "assert.h"
#include "tensor.h"

static inline void	__ops_cpu_cross(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t i = 0; i < a->shape[0]; i++) {
		dst->data[0 + (i * dst->shape[1])] = (a->data[1 + (i * 3)] * b->data[2 + (i * 3)]) - (a->data[2 + (i * 3)] * b->data[1 + (i * 3)]);
		dst->data[1 + (i * dst->shape[1])] = (a->data[2 + (i * 3)] * b->data[0 + (i * 3)]) - (a->data[0 + (i * 3)] * b->data[2 + (i * 3)]);
		dst->data[2 + (i * dst->shape[1])] = (a->data[0 + (i * 3)] * b->data[1 + (i * 3)]) - (a->data[1 + (i * 3)] * b->data[0 + (i * 3)]);
	}
}

struct Tensor		*cross(struct Tensor *a, struct Tensor *b) {
	struct Tensor	*out;
	assert_tensor_has_dim(a, 3);
	assert_tensor_broadcastable(a, b);
	if ((out = tensor_init(a->shape[0], 3)) == NULL)
		return (NULL);
	__ops_cpu_cross(out, a, b);
	return (out);
}
