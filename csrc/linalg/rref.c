#include "tensor.h"

#include <math.h>

static void		row_swap(struct Tensor *mat, uint32_t a, uint32_t b) {
	f32_t		tmp;
	for (uint32_t index = 0; index < mat->shape[1]; index++) {
		tmp = mat->data[(a * mat->shape[1]) + index];
		mat->data[(a * mat->shape[1]) + index] = mat->data[(b * mat->shape[1]) + index];
		mat->data[(b * mat->shape[1]) + index] = tmp;
	}
}

static void		gauss_jordan_elimination(struct Tensor *mat) {
	uint32_t	row = 0;
	uint32_t	k;
	f32_t		f;
	f32_t		p;
	for (uint32_t c = 0; c < mat->shape[1]; c++) {
		k = row;
		for (uint32_t idx = row + 1; idx < mat->shape[0]; idx++)
			if (fabsf(mat->data[(idx * mat->shape[1]) + c]) > fabsf(mat->data[(k * mat->shape[1]) + c]))
				k = idx;
		p = mat->data[(k * mat->shape[1]) + c];
		if (fabsf(p) >= 1e-8) {
			for (uint32_t idx = 0; idx < mat->shape[1]; idx++)
				mat->data[(k * mat->shape[1]) + idx] /= p;
			if (k != row)
				row_swap(mat, k, row);
			for (uint32_t i = 0; i < mat->shape[0]; i++) {
				if (i != row) {
					f = mat->data[(i * mat->shape[1]) + c];
					for (uint32_t j = 0; j < mat->shape[1]; j++)
						mat->data[(i * mat->shape[1]) + j] -= (mat->data[(row * mat->shape[1]) + j] * f);
				}
			}
			row = row + 1;
		}
	}
}

struct Tensor		*rref(struct Tensor *a) {
	struct Tensor	*out;
	if ((out = tensor_init_from_tensor(a)) == NULL)
		return (NULL);
	gauss_jordan_elimination(out);
	return (out);
}
