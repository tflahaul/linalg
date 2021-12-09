#include "assert.h"
#include "tensor.h"
#include "linalg.h"

static inline void	__ops_cpu_mm(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t k = 0; k < a->shape[1]; k++)
		for (uint32_t i = 0; i < a->shape[0]; i++)
			for (uint32_t j = 0; j < dst->shape[1]; j++)
				dst->data[i * b->shape[1] + j] += a->data[i * b->shape[1] + k] * b->data[k * b->shape[1] + j];
}

struct Tensor		*mm(struct Tensor *a, struct Tensor *b) {
	struct Tensor	*out;
	if ((b->shape[0] == 1) || (b->shape[1] == 1))
		return (linear_combination(a, b));
	assert_tensor_mm_able(a, b);
	if ((out = tensor_init_constant(a->shape[0], b->shape[1], 0.)) == NULL)
		return (NULL);
	__ops_cpu_mm(out, a, b);
	return (out);
}
