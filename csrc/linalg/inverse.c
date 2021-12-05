#include "assert.h"
#include "tensor.h"

struct Tensor		*inverse(struct Tensor *a) {
	assert_tensor_is_square(a);
	return (a);
}
