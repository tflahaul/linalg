#include "tensor.h"

static inline void	__ops_cumprod_cpu(struct Tensor *dst, struct Tensor *src) {
	float		cumulative_prod;
	for (uint32_t i = 0; i < dst->shape[0]; i++) {
		cumulative_prod = 1.;
		for (uint32_t j = 0; j < dst->shape[1]; j++) {
			cumulative_prod *= src->data[i * src->shape[1] + j];
			dst->data[i * dst->shape[1] + j] = cumulative_prod;
		}
	}
}

struct Tensor		*cumprod(struct Tensor *tensor) {
	struct Tensor	*out = tensor_init(tensor->shape[0], tensor->shape[1]);
	__ops_cumprod_cpu(out, tensor);
	return (out);
}
