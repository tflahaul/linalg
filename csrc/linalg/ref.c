#include "assert.h"
#include "tensor.h"

#include <math.h> // needed for fasbf

static inline void	swap(struct Tensor *a, uint32_t x, uint32_t y) {
	float		tmp;
	for (uint32_t index = 0; index < a->shape[1]; index++) {
		tmp = a->data[x * a->shape[1] + index];
		a->data[x * a->shape[1] + index] = a->data[y * a->shape[1] + index];
		a->data[y * a->shape[1] + index] = tmp;
	}
}

static void		gaussian_elimination(struct Tensor *a) {
	uint32_t	h = 0;
	uint32_t	k = 0;
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
			h = h + 1;
			k = k + 1;
		}
	}
}

struct Tensor		*ref(struct Tensor *tensor) {
	struct Tensor	*out = tensor_init(tensor->shape[0], tensor->shape[1]);
	gaussian_elimination(out);
	return (out);
}

struct Tensor		*ref_(struct Tensor *tensor) {
	gaussian_elimination(tensor);
	return (tensor);
}
