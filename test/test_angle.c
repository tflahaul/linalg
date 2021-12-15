// cc test_angle.c -I include linalg.a

#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {1, 0};
	float d1[] = {0, 1};

	float d2[] = {-1, 1};
	float d3[] = {1, -1};

	float d4[] = {2, 1};
	float d5[] = {4, 2};

	float d6[] = {1, 2, 3, 4, 5, 6};

	struct Tensor *a = tensor_init_from_array(d0, 1, 2);
	struct Tensor *b = tensor_init_from_array(d0, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> angle: %f\n", angle(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  1.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d0, 1, 2);
	b = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> angle: %f\n", angle(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  0.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 1, 2);
	b = tensor_init_from_array(d3, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> angle: %f\n", angle(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  -1.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d4, 1, 2);
	b = tensor_init_from_array(d5, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> angle: %f\n", angle(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  1.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d6, 1, 3);
	b = tensor_init_from_array(d6+3, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> angle: %f\n", angle(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  0.974631846

	return (0);
}
