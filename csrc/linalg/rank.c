#include "tensor.h"

#include <math.h>

static inline void	swap(struct Tensor *a, uint32_t x, uint32_t y) {
	float		tmp;
	for (uint32_t index = 0; index < a->shape[1]; index++) {
		tmp = a->data[x * a->shape[1] + index];
		a->data[x * a->shape[1] + index] = a->data[y * a->shape[1] + index];
		a->data[y * a->shape[1] + index] = tmp;
	}
}

static uint32_t		gaussian_elimination_rank(struct Tensor *a) {
	uint32_t	h = 0;
	uint32_t	k = 0;
	uint32_t	p = 0;
	uint32_t	index;
	float		f;
	while (h < a->shape[0] && k < a->shape[1]) {
		index = h;
		for (uint32_t i = h + 1; i < a->shape[0]; i++)
			if (fabsf(a->data[i * a->shape[1] + k]) > fabsf(a->data[index * a->shape[1] + k]))
				index = i;
		if (fabsf(a->data[index * a->shape[1] + k]) < 1e-8) { // no pivot
			k = k + 1;
		} else {
			if (h != index)
				swap(a, h, index);
			for (uint32_t i = h + 1; i < a->shape[0]; i++) {
				f = a->data[i * a->shape[1] + k] / a->data[h * a->shape[1] + k];
				a->data[i * a->shape[1] + k] = 0.;
				for (uint32_t j = k + 1; j < a->shape[1]; j++)
					a->data[i * a->shape[1] + j] -= (a->data[h * a->shape[1] + j] * f);
			}
			p = p + 1;
			h = h + 1;
			k = k + 1;
		}
	}
	return (p);
}

uint32_t		rank(struct Tensor *a) {
	struct Tensor	*ref;
	uint32_t	pivots = 0;
	if ((ref = tensor_init_from_tensor(a)) == NULL)
		return (pivots);
	pivots = gaussian_elimination_rank(ref);
	tensor_free(ref);
	return (pivots);
}
