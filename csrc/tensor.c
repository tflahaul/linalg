#include "tensor.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Tensor		*tensor_init(uint32_t n, uint32_t m) {
	struct Tensor	*tensor;
	if ((tensor = (struct Tensor *)malloc(sizeof(struct Tensor))) == NULL)
		return (NULL);
	uint32_t items = (n * m);
	if ((tensor->data = (f32_t *)malloc(sizeof(f32_t) * items)) == NULL)
		return (NULL);
	tensor->shape[0] = n;
	tensor->shape[1] = m;
	return (tensor);
}

struct Tensor		*tensor_init_random(uint32_t n, uint32_t m) {
	struct Tensor	*tensor;
	if ((tensor = tensor_init(n, m)) == NULL)
		return (NULL);
	srand((uint32_t)time(NULL) + rand());
	for (uint32_t index = 0; index < TENSOR_NUMEL(tensor); index++)
		tensor->data[index] = (f32_t)rand() / RAND_MAX;
	return (tensor);
}

struct Tensor		*tensor_init_constant(uint32_t n, uint32_t m, f32_t x) {
	struct Tensor	*tensor;
	if ((tensor = tensor_init(n, m)) == NULL)
		return (NULL);
	for (uint32_t index = 0; index < (n * m); index++)
		tensor->data[index] = x;
	return (tensor);
}

struct Tensor		*tensor_init_from_array(f32_t *data, uint32_t r, uint32_t c) {
	struct Tensor	*tensor;
	if ((tensor = tensor_init(r, c)) == NULL)
		return (NULL);
	memcpy(tensor->data, data, (sizeof(f32_t) * r * c));
	return (tensor);
}

struct Tensor		*tensor_init_from_tensor(struct Tensor *src) {
	struct Tensor	*tensor;
	if ((tensor = tensor_init(src->shape[0], src->shape[1])) == NULL)
		return (NULL);
	memcpy(tensor->data, src->data, (sizeof(f32_t) * TENSOR_NUMEL(src)));
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
