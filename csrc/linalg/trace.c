#include "assert.h"
#include "tensor.h"

f32_t		trace(struct Tensor *a) {
	f32_t	trace = 0.;
	assert_tensor_is_square(a);
	for (uint32_t index = 0; index < a->shape[0]; index++)
		trace = trace + a->data[index + index * a->shape[1]];
	return (trace);
}
