#include "tensor.h"

static inline void	__ops_cpu_add(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = a->data[index] + b->data[index];
}

static inline void	__ops_cpu_sub(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = a->data[index] - b->data[index];
}

static inline void	__ops_cpu_mul(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = a->data[index] * b->data[index];
}

static inline void	__ops_cpu_scl(struct Tensor *dst, struct Tensor *a, f32_t f) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = a->data[index] * f;
}

struct Tensor		*add(struct Tensor *a, struct Tensor *b) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[0], a->shape[1])) == NULL)
		return (NULL);
	__ops_cpu_add(out, a, b);
	return (out);
}

struct Tensor		*sub(struct Tensor *a, struct Tensor *b) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[0], a->shape[1])) == NULL)
		return (NULL);
	__ops_cpu_sub(out, a, b);
	return (out);
}

struct Tensor		*mul(struct Tensor *a, struct Tensor *b) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[0], a->shape[1])) == NULL)
		return (NULL);
	__ops_cpu_mul(out, a, b);
	return (out);
}

struct Tensor		*scl(struct Tensor *a, f32_t f) {
	struct Tensor	*out;
	if ((out = tensor_init(a->shape[0], a->shape[1])) == NULL)
		return (NULL);
	__ops_cpu_scl(out, a, f);
	return (out);
}
