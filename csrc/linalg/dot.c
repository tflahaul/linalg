#include "assert.h"
#include "tensor.h"

float		dot(struct Tensor *lhs, struct Tensor *rhs) {
	float	out = 0.;
	__assert_tensor_is_vector(lhs);
	__assert_tensor_is_vector(rhs);
	__assert_broadcastable(lhs, rhs);
	for (uint32_t index = 0; index < TENSOR_NUMEL(lhs); index++)
		out = out + (lhs->data[index] * rhs->data[index]);
	return (out);
}
