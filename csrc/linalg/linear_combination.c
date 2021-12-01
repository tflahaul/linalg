#include "tensor.h"

static inline void	__ops_cpu_linear_comb(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t i = 0; i < a->shape[1]; i++)
		for (uint32_t j = 0; j < a->shape[0]; j++)
			dst->data[i] += (b->data[j] * a->data[i + (j * a->shape[1])]);
}

struct Tensor		*linear_combination(struct Tensor *a, struct Tensor *coefs) {
	struct Tensor	*out;
	if ((out = tensor_init_constant(a->shape[1], 1, 0.)) == NULL)
		return (NULL);
	__ops_cpu_linear_comb(out, a, coefs);
	return (out);
}
