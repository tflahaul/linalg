#include "assert.h"
#include "tensor.h"
#include "linalg.h"

static struct Tensor	*augmented_matrix(struct Tensor *a) {
	struct Tensor	*aug = tensor_init_constant(a->shape[0], 2 * a->shape[1], 0.);
	for (uint32_t i = 0; i < a->shape[0]; i++) {
		for (uint32_t j = 0; j < a->shape[1]; j++)
			aug->data[i * aug->shape[1] + j] = a->data[i * a->shape[1] + j];
		aug->data[i * aug->shape[1] + i + a->shape[1]] = 1.;
	}
	return (aug);
}

static inline void	extract_inverse_from_aug(struct Tensor *dst, struct Tensor *aug) {
	for (uint32_t i = 0; i < dst->shape[0]; i++)
		for (uint32_t j = 0; j < dst->shape[1]; j++)
			dst->data[i * dst->shape[0] + j] = aug->data[i * aug->shape[1] + j + dst->shape[1]];
}

struct Tensor		*inverse(struct Tensor *tensor) {
	struct Tensor	*aug, *inv;
	__assert_tensor_is_square(tensor);
	aug = augmented_matrix(tensor);
	__assert_tensor_invertible(rref_(aug));
	inv = tensor_init(tensor->shape[0], tensor->shape[1]);
	extract_inverse_from_aug(inv, aug);
	tensor_free(aug);
	return (inv);
}

struct Tensor		*inverse_(struct Tensor *tensor) {
	struct Tensor	*aug;
	__assert_tensor_is_square(tensor);
	aug = augmented_matrix(tensor);
	__assert_tensor_invertible(rref_(aug));
	extract_inverse_from_aug(tensor, aug);
	tensor_free(aug);
	return (tensor);
}
