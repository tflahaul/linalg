// cc test_linear_combination.c -I include linalg.a

#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	float c0[] = {10, -2, 0.5};

	float d1[] = {1, 2, 3, 0, 10, -100};
	float c1[] = {10, -2};

	struct Tensor *a = tensor_init_from_array(d0, 3, 3);
	struct Tensor *b = tensor_init_from_array(c0, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> linear:\n");
	tensor_print(linear_combination(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[10.0000, -2.0000, 0.5000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 2, 3);
	b = tensor_init_from_array(c1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> linear:\n");
	tensor_print(linear_combination(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[ 10.0000, 0.0000], 230.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(3, 3);
	b = tensor_init_random(1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> linear:\n");
	tensor_print(linear_combination(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :   error because of shapes
	return (0);
}
