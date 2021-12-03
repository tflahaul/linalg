#include "tensor.h"

#include <math.h>

static void		swap_rows(struct Tensor *mat, uint32_t a, uint32_t b) {
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
	f32_t		pivot;
	for (uint32_t c = 0; c < mat->shape[1]; c++) {
		k = 0;
		for (uint32_t idx = row; idx < mat->shape[0]; idx++)
			if (fabsf(mat->data[(idx * mat->shape[1]) + c]) > fabsf(mat->data[(k * mat->shape[1]) + c]))
				k = idx;
		pivot = mat->data[(k * mat->shape[1]) + c];
		if (pivot != 0) {
			for (uint32_t idx = 0; idx < mat->shape[1]; idx++)
				mat->data[(k * mat->shape[1]) + idx] /= pivot;
			if (k != row)
				swap_rows(mat, k, row);
			for (uint32_t idx = 0; idx < mat->shape[0]; idx++) {
				if (idx != row) {
					for (uint32_t i = 0; i < mat->shape[1]; i++) {
						mat->data[(idx * mat->shape[1]) + i] -= (mat->data[(row * mat->shape[1]) + i] * mat->data[(idx * mat->shape[1]) + c]);
					}
				}
			}
			row = row + 1;
		}
	}
}

struct Tensor		*row_echelon(struct Tensor *a) {
	struct Tensor	*out;
	if ((out = tensor_init_from_tensor(a)) == NULL)
		return (NULL);
	gauss_jordan_elimination(out);
	tensor_print(out);
	return (NULL);
}
