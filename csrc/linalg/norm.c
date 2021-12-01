#include "tensor.h"

#include <math.h> // for powf

f32_t		norm(struct Tensor *a) {
	f32_t	norm = 0.;
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		norm = norm + powf(a->data[index], 2.);
	return (powf(norm, .5));
}

f32_t		norm_1(struct Tensor *a) {
	f32_t	norm = 0.;
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		norm = norm + fabsf(a->data[index]);
	return (norm);
}

f32_t		norm_inf(struct Tensor *a) {
	f32_t	norm = fabsf(a->data[0]);
	for (uint32_t index = 1; index < TENSOR_NUMEL(a); index++)
		if (fabsf(a->data[index]) > norm)
			norm = fabsf(a->data[index]);
	return (norm);
}
