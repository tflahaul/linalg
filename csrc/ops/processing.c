#include "assert.h"
#include "tensor.h"
#include "linalg.h"
#include "ops.h"

#include <math.h> // sqrtf in sdpa

struct Tensor		*pad(struct Tensor *tensor, uint32_t const right, uint32_t const left, float const value) {
	uint32_t const	p = (right + left);
	struct Tensor	*out = tensor_init_constant((tensor->shape[0] + p), (tensor->shape[1] + p), value);
	for (uint32_t i = 0; i < tensor->shape[0]; i++)
		for (uint32_t j = 0; j < tensor->shape[1]; j++)
			out->data[(i + right) * out->shape[1] + j + right] = tensor->data[i * tensor->shape[1] + j];
	return (out);
}

struct Tensor		*conv1d(struct Tensor *tensor, struct Tensor *kernel,
				float const bias, uint32_t const stride) {
	struct Tensor	*out;
	__assert_tensor_is_vector(tensor);
	__assert_tensor_is_vector(kernel);
	__assert_non_zero_stride(stride);
	__assert_conv_kernel_size(tensor, kernel);
	out = tensor_init_constant(1, ((tensor->shape[1] - kernel->shape[1] + stride) / stride), bias);
	for (uint32_t index = 0; index < out->shape[1]; index++)
		for (uint32_t k = 0; k < kernel->shape[1]; k++)
			out->data[index] += (tensor->data[(index * stride) + k] * kernel->data[k]);
	return (out);
}

struct Tensor		*conv2d(struct Tensor *tensor, struct Tensor *kernel,
				float const bias, uint32_t const stride) {
	__assert_non_zero_stride(stride);
	__assert_conv_kernel_size(tensor, kernel);
	uint32_t const	h = ((tensor->shape[0] - (kernel->shape[0] - 1) - 1) / stride) + 1;
	uint32_t const	w = ((tensor->shape[1] - (kernel->shape[1] - 1) - 1) / stride) + 1;
	struct Tensor	*out = tensor_init_constant(h, w, bias);
	for (uint32_t i = 0; i < h; i++)
		for (uint32_t j = 0; j < w; j++)
			for (uint32_t k = 0; k < kernel->shape[0]; k++)
				for (uint32_t l = 0; l < kernel->shape[1]; l++)
					out->data[i * w + j] += kernel->data[k * kernel->shape[1] + l] * tensor->data[(i + k) * tensor->shape[1] + l + j];
	return (out);
}

struct Tensor		*sdpa(struct Tensor *q, struct Tensor *k, struct Tensor *v) {
	struct Tensor	*out, *attn;
	attn = softmax_(scl_(mm(q, k), (1 / sqrtf(k->shape[1]))));
	out = mm(attn, v);
	tensor_free(attn);
	return (out);
}
