#include "tensor.h"
#include "linalg.h"

#include <math.h>

uint32_t		rank(struct Tensor *tensor) {
	struct Tensor	*out;
	uint32_t	diag = 0;
	if ((out = ref(tensor)) == NULL)
		return (0);
	for (uint32_t index = 0; index < out->shape[0]; index++)
		if (fabsf(out->data[index * out->shape[1] + index]) > 1e-8)
			diag = diag + 1;
	tensor_free(out);
	return (diag);
}
