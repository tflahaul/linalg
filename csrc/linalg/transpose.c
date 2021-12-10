#include "tensor.h"

static inline void	__ops_cpu_transpose(struct Tensor *dst, struct Tensor *a) {
	for (uint32_t i = 0; i < a->shape[1]; i++)
		for (uint32_t j = 0; j < a->shape[0]; j++)
			dst->data[i * a->shape[0] + j] = a->data[j * a->shape[1] + i];
}

struct Tensor		*transpose(struct Tensor *tensor) {
	struct Tensor	*out;
	if ((out = tensor_init(tensor->shape[1], tensor->shape[0])) == NULL)
		return (NULL);
	__ops_cpu_transpose(out, tensor);
	return (out);
}
