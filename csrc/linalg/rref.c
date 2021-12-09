#include "tensor.h"

#include <math.h>

static void		swap(struct Tensor *mat, uint32_t a, uint32_t b) {
	float		tmp;
	for (uint32_t index = 0; index < mat->shape[1]; index++) {
		tmp = mat->data[a * mat->shape[1] + index];
		mat->data[a * mat->shape[1] + index] = mat->data[b * mat->shape[1] + index];
		mat->data[b * mat->shape[1] + index] = tmp;
	}
}

static uint32_t		argmax(struct Tensor *a, uint32_t start, uint32_t col) {
	uint32_t	index = start;
	for (uint32_t i = start + 1; i < a->shape[1]; i++)
		if (fabsf(a->data[i * a->shape[1] + col]) > fabsf(a->data[start * a->shape[1] + col]))
			index = i;
	return (index);
}

static void		gauss_jordan_elimination(struct Tensor *a) {
	uint32_t	r = 0;
	uint32_t	k;
	float		f;
	float		p;
	for (uint32_t c = 0; c < a->shape[1]; c++) {
		k = argmax(a, r, c);
		p = a->data[k * a->shape[1] + c];
		if (fabsf(p) >= 1e-8) {
			for (uint32_t index = 0; index < a->shape[1]; index++)
				a->data[k * a->shape[1] + index] /= p;
			if (k != r)
				swap(a, k, r);
			for (uint32_t i = 0; i < a->shape[0]; i++) {
				if (i != r) {
					f = a->data[i * a->shape[1] + c];
					for (uint32_t j = 0; j < a->shape[1]; j++)
						a->data[i * a->shape[1] + j] -= (a->data[r * a->shape[1] + j] * f);
				}
			}
			r = r + 1;
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

struct Tensor		*rref_(struct Tensor *a) {
	struct Tensor	*out = a;
	gauss_jordan_elimination(out);
	return (out);
}
