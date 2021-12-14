#include "assert.h"
#include "tensor.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Tensor		*tensor_init(uint32_t n, uint32_t m) {
	struct Tensor	*tensor;
	__assert_non_null((tensor = (struct Tensor *)malloc(sizeof(struct Tensor))));
	__assert_non_null((tensor->data = (float *)malloc(sizeof(float) * n * m)));
	tensor->shape[0] = n;
	tensor->shape[1] = m;
	return (tensor);
}

struct Tensor		*tensor_init_random(uint32_t n, uint32_t m) {
	struct Tensor	*tensor = tensor_init(n, m);
	srand((uint32_t)time(NULL) + rand());
	for (uint32_t index = 0; index < TENSOR_NUMEL(tensor); index++)
		tensor->data[index] = (float)rand() / RAND_MAX;
	return (tensor);
}

struct Tensor		*tensor_init_constant(uint32_t n, uint32_t m, float x) {
	struct Tensor	*tensor = tensor_init(n, m);
	for (uint32_t index = 0; index < (n * m); index++)
		tensor->data[index] = x;
	return (tensor);
}

struct Tensor		*tensor_init_from_array(float *data, uint32_t r, uint32_t c) {
	struct Tensor	*tensor = tensor_init(r, c);
	memcpy(tensor->data, data, (sizeof(float) * r * c));
	return (tensor);
}

struct Tensor		*tensor_init_from_tensor(struct Tensor *src) {
	struct Tensor	*tensor = tensor_init(src->shape[0], src->shape[1]);
	memcpy(tensor->data, src->data, (sizeof(float) * TENSOR_NUMEL(src)));
	return (tensor);
}

void			tensor_print(struct Tensor *tensor) {
	printf("tensor([");
	for (uint_fast32_t i = 0; i < tensor->shape[0]; i++) {
		printf(i > 0 ? "\t[" : "[");
		for (uint_fast32_t j = 0; j < tensor->shape[1]; j++) {
			printf("%.4f", tensor->data[j + (i * tensor->shape[1])]);
			if (j + 1 < tensor->shape[1])
				printf(", ");
		}
		printf((i + 1 < tensor->shape[0]) ? "],\n" : "]])\n");
	}
}

void			tensor_free(struct Tensor *tensor) {
	free(tensor->data);
	free(tensor);
}
