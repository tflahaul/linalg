#include "assert.h"
#include "tensor.h"

static inline void	__ops_cpu_add(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = a->data[index] + b->data[index];
}

static inline void	__ops_cpu_sub(struct Tensor *dst, struct Tensor *a, struct Tensor *b) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = a->data[index] - b->data[index];
}

static inline void	__ops_cpu_scl(struct Tensor *dst, struct Tensor *a, float f) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(dst); index++)
		dst->data[index] = a->data[index] * f;
}

struct Tensor		*add(struct Tensor *lhs, struct Tensor *rhs) {
	struct Tensor	*out;
	__assert_broadcastable(lhs, rhs);
	out = tensor_init(lhs->shape[0], lhs->shape[1]);
	__ops_cpu_add(out, lhs, rhs);
	return (out);
}

struct Tensor		*sub(struct Tensor *lhs, struct Tensor *rhs) {
	struct Tensor	*out;
	__assert_broadcastable(lhs, rhs);
	out = tensor_init(lhs->shape[0], lhs->shape[1]);
	__ops_cpu_sub(out, lhs, rhs);
	return (out);
}

struct Tensor		*scl(struct Tensor *tensor, float f) {
	struct Tensor	*out;
	out = tensor_init(tensor->shape[0], tensor->shape[1]);
	__ops_cpu_scl(out, tensor, f);
	return (out);
}
