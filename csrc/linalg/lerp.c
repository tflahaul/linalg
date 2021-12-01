#include "assert.h"
#include "tensor.h"

static inline void	__ops_cpu_lerp(struct Tensor *dst, struct Tensor *a, struct Tensor *b, f32_t k) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		dst->data[index] = a->data[index] + ((b->data[index] - a->data[index]) * k);
}

struct Tensor		*lerp(struct Tensor *a, struct Tensor *b, f32_t k) {
	struct Tensor	*out;
	assert_tensor_broadcastable(a, b);
	if ((out = tensor_init(a->shape[0], a->shape[1])) == NULL)
		return (NULL);
	__ops_cpu_lerp(out, a, b, k);
	return (out);
}
