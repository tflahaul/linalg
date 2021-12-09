#include "assert.h"
#include "tensor.h"
#include "linalg.h"

#include <stdlib.h>
#include <stdio.h>

void	assert_tensor_broadcastable(struct Tensor *a, struct Tensor *b) {
	if (((a->shape[0] == b->shape[0]) && (a->shape[1] == b->shape[1])) == 0) {
		fprintf(stderr, "error: tensors must be broadcastable\n");
		exit(EXIT_FAILURE);
	}
}

void	assert_tensor_is_vector(struct Tensor *a) {
	if (((a->shape[0] == 1) || (a->shape[1] == 1)) == 0) {
		fprintf(stderr, "error: tensor is not vector\n");
		exit(EXIT_FAILURE);
	}
}

void	assert_tensor_is_square(struct Tensor *a) {
	if ((a->shape[0] == a->shape[1]) == 0) {
		fprintf(stderr, "error: tensor is not a square matrix\n");
		exit(EXIT_FAILURE);
	}
}

void	assert_tensor_has_dim(struct Tensor *a, uint32_t dim) {
	if ((a->shape[1] == dim) == 0) {
		fprintf(stderr, "error: tensor size must be %u at latest dim\n", dim);
		exit(EXIT_FAILURE);
	}
}

void	assert_tensor_mm_able(struct Tensor *a, struct Tensor *b) {
	if ((a->shape[1] == b->shape[0]) == 0) {
		fprintf(stderr, "error: %ux%u and %ux%u cannot be multiplied\n",\
			a->shape[0], a->shape[1], b->shape[0], b->shape[1]);
		exit(EXIT_FAILURE);
	}
}

void	assert_invertible(struct Tensor *a) {
	for (uint32_t index = 0; index < a->shape[0]; index++) {
		if (a->data[(index * a->shape[1]) + index] == 0.0) {
			fprintf(stderr, "error: matrix is singular.\n");
			exit(EXIT_FAILURE);
		}
	}
}
