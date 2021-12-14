#include "assert.h"
#include "tensor.h"

#include <math.h>

static inline void	__ops_relu_cpu(struct Tensor *dst, struct Tensor *src) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = src->data[index] > 0. ? src->data[index] : 0.;
}

struct Tensor		*relu(struct Tensor *tensor) {
	struct Tensor	*out = tensor_init(tensor->shape[0], tensor->shape[1]);
	__ops_relu_cpu(out, tensor);
	return (out);
}

struct Tensor		*softmax_(struct Tensor *tensor) {
	float		max = tensor->data[0];
	float		sum = 0.;
	float		offset;
	for (uint32_t index = 1; index < TENSOR_NUMEL(tensor); index++)
		if (max < tensor->data[index])
			max = tensor->data[index];
	for (uint32_t index = 0; index < TENSOR_NUMEL(tensor); index++)
		sum = sum + expf(tensor->data[index] - max);
	offset = max + logf(sum);
	for (uint32_t index = 0; index < TENSOR_NUMEL(tensor); index++)
		tensor->data[index] = expf(tensor->data[index] - offset);
	return (tensor);
}
