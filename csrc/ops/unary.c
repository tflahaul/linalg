#include "assert.h"
#include "tensor.h"

#include <math.h>

static inline void	__ops_relu_cpu(struct Tensor *dst, struct Tensor *src) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = src->data[index] > 0. ? src->data[index] : 0.;
}

static inline void	__ops_softmax_cpu(struct Tensor *dst, struct Tensor *src) {
	float		max_item = src->data[0];
	float		sum = 0.;
	float		offset;
	for (uint32_t index = 1; index < TENSOR_NUMEL(src); index++)
		if (src->data[index] > max_item)
			max_item = src->data[index];
	for (uint32_t index = 0; index < TENSOR_NUMEL(src); index++)
		sum = sum + expf(src->data[index] - max_item);
	offset = max_item + logf(sum);
	for (uint32_t index = 0; index < TENSOR_NUMEL(src); index++)
		dst->data[index] = expf(src->data[index] - offset);
}

struct Tensor		*relu(struct Tensor *tensor) {
	struct Tensor	*out = tensor_init(tensor->shape[0], tensor->shape[1]);
	__ops_relu_cpu(out, tensor);
	return (out);
}

struct Tensor		*relu_(struct Tensor *tensor) {
	__ops_relu_cpu(tensor, tensor);
	return (tensor);
}

struct Tensor		*softmax(struct Tensor *tensor) {
	struct Tensor	*out = tensor_init(tensor->shape[0], tensor->shape[1]);
	__ops_softmax_cpu(out, tensor);
	return (out);
}

struct Tensor		*softmax_(struct Tensor *tensor) {
	__ops_softmax_cpu(tensor, tensor);
	return (tensor);
}
