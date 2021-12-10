#include "tensor.h"

#include <math.h> // for powf

float		norm(struct Tensor *tensor) {
	float	norm = powf(tensor->data[0], 2.);
	for (uint32_t index = 1; index < TENSOR_NUMEL(tensor); index++)
		norm = norm + powf(tensor->data[index], 2.);
	return (powf(norm, .5));
}

float		norm_1(struct Tensor *tensor) {
	float	norm = fabsf(tensor->data[0]);
	for (uint32_t index = 1; index < TENSOR_NUMEL(tensor); index++)
		norm = norm + fabsf(tensor->data[index]);
	return (norm);
}

float		norm_inf(struct Tensor *tensor) {
	float	norm = fabsf(tensor->data[0]);
	for (uint32_t index = 1; index < TENSOR_NUMEL(tensor); index++)
		if (fabsf(tensor->data[index]) > norm)
			norm = fabsf(tensor->data[index]);
	return (norm);
}
