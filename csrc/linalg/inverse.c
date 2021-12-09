#include "assert.h"
#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

static struct Tensor	*augmented_matrix(struct Tensor *a) {
	struct Tensor	*aug;
	if ((aug = tensor_init(a->shape[0], 2 * a->shape[1])) == NULL)
		return (NULL);
	for (uint32_t i = 0; i < a->shape[0]; i++) {
		for (uint32_t j = 0; j < a->shape[1]; j++)
			aug->data[(i * aug->shape[1]) + j] = a->data[(i * a->shape[1]) + j];
		aug->data[(i * aug->shape[1]) + i + a->shape[1]] = 1.;
	}
	return (aug);
}

static struct Tensor	*extract_inverse_from_aug(struct Tensor *a) {
	struct Tensor	*inv;
	if ((inv = tensor_init(a->shape[0], (0.5 * a->shape[1]))) == NULL)
		return (NULL);
	for (uint32_t i = 0; i < inv->shape[0]; i++)
		for (uint32_t j = 0; j < inv->shape[1]; j++)
			inv->data[(i * a->shape[0]) + j] = a->data[(i * a->shape[1]) + j + inv->shape[1]];
	return (inv);
}

struct Tensor		*inverse(struct Tensor *a) {
	struct Tensor	*aug, *inv;
	assert_tensor_is_square(a);
	assert_non_zero_determinant(a);
	if ((aug = augmented_matrix(a)) == NULL)
		return (NULL);
	if ((inv = extract_inverse_from_aug(rref_(aug))) == NULL) {
		tensor_free(aug);
		return (NULL);
	}
	tensor_free(aug);
	return (inv);
}
