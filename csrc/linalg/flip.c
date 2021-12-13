#include "assert.h"
#include "tensor.h"

static inline void	__ops_flip_cpu(struct Tensor *dst, struct Tensor *src) {
	for (uint32_t i = 0; i < dst->shape[0]; i++)
		for (uint32_t j = 0; j < dst->shape[1]; j++)
			dst->data[i * dst->shape[1] + j] = src->data[i * src->shape[1] + src->shape[1] - j - 1];
}

struct Tensor		*flip(struct Tensor *tensor) {
	struct Tensor	*out = tensor_init(tensor->shape[0], tensor->shape[1]);
	__ops_flip_cpu(out, tensor);
	return (out);
}
