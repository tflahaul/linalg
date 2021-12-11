// cc test_lerp.c -I include linalg.a

#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {2, 1};
	float d1[] = {4, 2};

	float d2[] = {2, 1, 3, 4};
	float d3[] = {20, 10, 30, 40};

	struct Tensor *a = tensor_init_from_array(d0, 1, 2);
	struct Tensor *b = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> lerp:\n");
	tensor_print(lerp(a, b, 0.3));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[2.6000, 1.3000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 2, 2);
	b = tensor_init_from_array(d3, 2, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> lerp:\n");
	tensor_print(lerp(a, b, 0.5));
	tensor_free(a);
	tensor_free(b);

// expected :   tensor([[11.0000,  5.5000],
//	                [16.5000, 22.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(2, 2);
	b = tensor_init_random(2, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> lerp:\n");
	tensor_print(lerp(a, b, 0.5));
	tensor_free(a);
	tensor_free(b);

// expected :   error because of different shapes

	return (0);
}
