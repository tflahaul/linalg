#include "assert.h"
#include "tensor.h"

float		trace(struct Tensor *tensor) {
	float	trace = 0.;
	assert_tensor_is_square(tensor);
	for (uint32_t index = 0; index < tensor->shape[0]; index++)
		trace = trace + tensor->data[index * tensor->shape[1] + index];
	return (trace);
}
