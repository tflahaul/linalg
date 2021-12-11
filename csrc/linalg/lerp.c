#include "assert.h"
#include "tensor.h"

static inline void	__ops_cpu_lerp(struct Tensor *dst, struct Tensor *a, struct Tensor *b, float k) {
	for (uint32_t index = 0; index < TENSOR_NUMEL(a); index++)
		dst->data[index] = a->data[index] + ((b->data[index] - a->data[index]) * k);
}

struct Tensor		*lerp(struct Tensor *lhs, struct Tensor *rhs, float k) {
	struct Tensor	*out;
	__assert_broadcastable(lhs, rhs);
	out = tensor_init(lhs->shape[0], lhs->shape[1]);
	__ops_cpu_lerp(out, lhs, rhs, k);
	return (out);
}
