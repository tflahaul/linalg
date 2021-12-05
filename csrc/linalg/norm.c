#include "tensor.h"

#include <math.h> // for powf

float		norm(struct Tensor *a) {
	float	norm = 0.;
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		norm = norm + powf(a->data[index], 2.);
	return (powf(norm, .5));
}

float		norm_1(struct Tensor *a) {
	float	norm = 0.;
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		norm = norm + fabsf(a->data[index]);
	return (norm);
}

float		norm_inf(struct Tensor *a) {
	float	norm = fabsf(a->data[0]);
	for (uint32_t index = 1; index < TENSOR_NUMEL(a); index++)
		if (fabsf(a->data[index]) > norm)
			norm = fabsf(a->data[index]);
	return (norm);
}
