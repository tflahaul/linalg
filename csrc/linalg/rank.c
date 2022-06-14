#include "assert.h"
#include "tensor.h"
#include "linalg.h"

#include <math.h> // fabsf

uint32_t		rank(struct Tensor *tensor) {
	uint32_t	index = 0;
	struct Tensor	*out = ref(tensor);
	while ((index < out->shape[0]) && (fabsf(out->data[index * out->shape[1] + index]) > 1e-8))
		index = index + 1;
	tensor_free(out);
	return (index);
}
