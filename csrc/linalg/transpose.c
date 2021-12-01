#include "tensor.h"

static inline void	__ops_cpu_transpose(struct Tensor *dst, struct Tensor *a) {
	for (uint32_t i = 0; i < a->shape[1]; i++)
		for (uint32_t j = 0; j < a->shape[0]; j++)
			dst->data[j + (i * a->shape[0])] = a->data[i + (j * a->shape[1])];
}

struct Tensor		*transpose(struct Tensor *a) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[1], a->shape[0])) == NULL)
		return (NULL);
	__ops_cpu_transpose(out, a);
	return (out);
}
