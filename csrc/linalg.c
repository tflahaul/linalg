#include "tensor.h"
#include "ops.h"

#include <assert.h>
#include <math.h> // needed for powf

#ifndef NULL
# define NULL (void *)0
#endif /* NULL */

#define abs(x)		(x < 0 ? -x : x)

struct Tensor		*linear_combination(struct Tensor *a, struct Tensor *coefs) {
	struct Tensor	*out;
	if ((out = tensor_constant_init(a->shape[1], 1, 0.)) == NULL)
		return (NULL);
	for (uint32_t i = 0; i < a->shape[1]; i++)
		for (uint32_t j = 0; j < a->shape[0]; j++)
			out->data[i] = out->data[i] + (coefs->data[j] * a->data[i + (j * a->shape[1])]);
	return (out);
}

struct Tensor		*lerp(struct Tensor *a, struct Tensor *b, f32_t k) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[0], a->shape[1])) == NULL)
		return (NULL);
	for (uint32_t index = 0; index < TENSOR_NUMEL(out); index++)
		out->data[index] = a->data[index] + (k * (b->data[index] - a->data[index]));
	return (out);
}

f32_t			dot(struct Tensor *a, struct Tensor *b) {
	f32_t		out = 0.;
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		out = out + (a->data[index] * b->data[index]);
	return (out);
}

f32_t			norm(struct Tensor *a) {
	f32_t		out = 0.;
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		out = out + powf(a->data[index], 2.);
	return (powf(out, .5));
}

f32_t			norm_1(struct Tensor *a) {
	f32_t		out = 0.;
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		out = out + abs(a->data[index]);
	return (out);
}

f32_t			norm_inf(struct Tensor *a) {
	f32_t		out = abs(a->data[0]);
	for (uint32_t index = 1; index < TENSOR_NUMEL(a); index++)
		if (abs(a->data[index]) > out)
			out = abs(a->data[index]);
	return (out);
}

f32_t			cos_angle(struct Tensor *a, struct Tensor *b) {
	return (dot(a, b) / (norm(a) * norm(b)));
}

struct Tensor		*cross(struct Tensor *a, struct Tensor *b) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[0], 3)) == NULL)
		return (NULL);
	for (uint32_t i = 0; i < a->shape[0]; i++) {
		out->data[0 + (i * out->shape[1])] = (a->data[1 + (i * 3)] * b->data[2 + (i * 3)]) - (a->data[2 + (i * 3)] * b->data[1 + (i * 3)]);
		out->data[1 + (i * out->shape[1])] = (a->data[2 + (i * 3)] * b->data[0 + (i * 3)]) - (a->data[0 + (i * 3)] * b->data[2 + (i * 3)]);
		out->data[2 + (i * out->shape[1])] = (a->data[0 + (i * 3)] * b->data[1 + (i * 3)]) - (a->data[1 + (i * 3)] * b->data[0 + (i * 3)]);
	}
	return (out);
}

struct Tensor		*mm(struct Tensor *a, struct Tensor *b) {
	if (TENSOR_ISVEC(b)) { return (linear_combination(a, b)); }
	struct Tensor	*out;
	if ((out = tensor_constant_init(a->shape[0], b->shape[1], 0.)) == NULL)
		return (NULL);
	for (uint32_t k = 0; k < a->shape[1]; k++)
		for (uint32_t i = 0; i < out->shape[0]; i++)
			for (uint32_t j = 0; j < out->shape[1]; j++)
				out->data[j + (i * out->shape[1])] += a->data[k + (i * out->shape[1])] * b->data[j + (k * out->shape[1])];
	return (out);
}

f32_t			trace(struct Tensor *a) {
	f32_t		out = 0.;
	for (uint32_t index = 0; index < a->shape[0]; index++)
		out = out + a->data[index + index * a->shape[1]];
	return (out);
}

struct Tensor		*transpose(struct Tensor *a) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[1], a->shape[0])) == NULL)
		return (NULL);
	for (uint32_t i = 0; i < a->shape[1]; i++)
		for (uint32_t j = 0; j < a->shape[0]; j++)
			out->data[j + (i * out->shape[1])] = a->data[i + (j * a->shape[1])];
	return (out);
}
