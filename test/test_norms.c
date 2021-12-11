// cc test_norms.c -I include linalg.a

#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {1, 2, 3};
	float d1[] = {-1, -2};

	struct Tensor *a = tensor_init_constant(1, 3, 0.0);
	tensor_print(a);
	printf("\n>>> norm_1: %f, norm: %f, norm_inf: %f\n", norm_1(a), norm(a), norm_inf(a));
	tensor_free(a);

// expected :  0.0, 0.0, 0.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d0, 1, 3);
	tensor_print(a);
	printf("\n>>> norm_1: %f, norm: %f, norm_inf: %f\n", norm_1(a), norm(a), norm_inf(a));
	tensor_free(a);

// expected :   6.0, 3.7417, 3.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	printf("\n>>> norm_1: %f, norm: %f, norm_inf: %f\n", norm_1(a), norm(a), norm_inf(a));
	tensor_free(a);

// expected :   3.0, 2.236067977, 2.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(3, 5);
	tensor_print(a);
	printf("\n>>> norm_1: %f, norm: %f, norm_inf: %f\n", norm_1(a), norm(a), norm_inf(a));
	tensor_free(a);

	return (0);
}
