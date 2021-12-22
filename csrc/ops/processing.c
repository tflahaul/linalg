#include "assert.h"
#include "tensor.h"
#include "linalg.h"
#include "ops.h"

#include <math.h> // sqrtf

struct Tensor		*conv1d(struct Tensor *tensor, struct Tensor *kernel,
				float const bias, uint32_t const stride) {
	struct Tensor	*out;
	__assert_tensor_is_vector(tensor);
	__assert_tensor_is_vector(kernel);
	__assert_conv1d_size(tensor, kernel);
	__assert_non_zero_stride(stride);
	out = tensor_init_constant(1, ((tensor->shape[1] - kernel->shape[1] + stride) / stride), bias);
	for (uint32_t index = 0; index < out->shape[1]; index++)
		for (uint32_t k = 0; k < kernel->shape[1]; k++)
			out->data[index] += (tensor->data[(index * stride) + k] * kernel->data[k]);
	return (out);
}

struct Tensor		*sdpa(struct Tensor *q, struct Tensor *k, struct Tensor *v) {
	struct Tensor	*out, *attn;
	attn = softmax_(scl_(mm(q, k), (1.0 / sqrtf(k->shape[1]))));
	out = mm(attn, v);
	tensor_free(attn);
	return (out);
}
