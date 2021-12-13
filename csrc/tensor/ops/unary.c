#include "assert.h"
#include "tensor.h"

static inline void	__ops_relu_cpu(struct Tensor *dst, struct Tensor *src) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = src->data[index] > 0. ? src->data[index] : 0.;
}

struct Tensor		*relu(struct Tensor *tensor) {
	struct Tensor	*out = tensor_init(tensor->shape[0], tensor->shape[1]);
	__ops_relu_cpu(out, tensor);
	return (out);
}
