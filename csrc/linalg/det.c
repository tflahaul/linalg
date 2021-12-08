#include "assert.h"
#include "tensor.h"

#include <math.h>

static inline void	swap(struct Tensor *a, uint32_t x, uint32_t y) {
	float		tmp;
	for (uint32_t index = 0; index < a->shape[1]; index++) {
		tmp = a->data[(x * a->shape[1]) + index];
		a->data[(x * a->shape[1]) + index] = a->data[(y * a->shape[1]) + index];
		a->data[(y * a->shape[1]) + index] = tmp;
	}
}

static float		gaussian_elimination_det(struct Tensor *a) {
	uint32_t	h = 0;
	uint32_t	k = 0;
	uint32_t	index;
	float		p = 1.0;
	float		f;
	while (h < a->shape[0] && k < a->shape[1]) {
		index = h;
		for (uint32_t i = h + 1; i < a->shape[0]; i++)
			if (fabsf(a->data[(i * a->shape[1]) + k]) > fabsf(a->data[(index * a->shape[1]) + k]))
				index = i;
		if (fabsf(a->data[(index * a->shape[1]) + k]) < 1e-8) { // no pivot
			k = k + 1;
		} else {
			if (h != index) {
				swap(a, h, index);
				p = -p;
			}
			for (uint32_t i = h + 1; i < a->shape[0]; i++) {
				f = a->data[(i * a->shape[1]) + k] / a->data[(h * a->shape[1]) + k];
				a->data[(i * a->shape[1]) + k] = 0.;
				for (uint32_t j = k + 1; j < a->shape[1]; j++)
					a->data[(i * a->shape[1]) + j] -= (a->data[(h * a->shape[1]) + j] * f);
			}
			h = h + 1;
			k = k + 1;
		}
	}
	return (p);
}

static float		det2x2(struct Tensor *a) {
	return (a->data[0] * a->data[3]) - (a->data[1] * a->data[2]);
}

static float		det3x3(struct Tensor *a) {
	return ((a->data[0] * a->data[4] * a->data[8]) + (a->data[1] * a->data[5] * a->data[6]) +\
		(a->data[2] * a->data[3] * a->data[7]) - (a->data[0] * a->data[5] * a->data[7]) -\
		(a->data[1] * a->data[3] * a->data[8]) - (a->data[2] * a->data[4] * a->data[6]));
}

static float		detnxn(struct Tensor *a) {
	struct Tensor	*ref;
	float		determinant = 1.0;
	float		sig;
	if ((ref = tensor_init_from_tensor(a)) == NULL)
		return (0.);
	sig = gaussian_elimination_det(ref);
	for (uint32_t index = 0; index < ref->shape[0]; index++)
		determinant *= ref->data[(index * ref->shape[1]) + index];
	tensor_free(ref);
	return (determinant * sig);
}

float		det(struct Tensor *a) {
	assert_tensor_is_square(a);
	if (a->shape[0] == 1)
		return (a->data[0]);
	if (a->shape[0] == 2)
		return det2x2(a);
	if (a->shape[0] == 3)
		return det3x3(a);
	return (detnxn(a));
}
