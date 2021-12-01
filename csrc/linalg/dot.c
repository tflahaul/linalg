#include "assert.h"
#include "tensor.h"

f32_t		dot(struct Tensor *a, struct Tensor *b) {
	f32_t	out = 0.;
	assert_tensor_is_vector(a);
	assert_tensor_broadcastable(a, b);
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		out = out + (a->data[index] * b->data[index]);
	return (out);
}
