#include "tensor.h"
#include "ops.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float		d1[] = {0.5, 1, 0.5};

	float		d2[] = {-2, 4, 6, 1, -8};
	float		d3[] = {-1, 1};

	struct Tensor	*a = tensor_init_from_array(d0, 1, 10);
	struct Tensor	*b = tensor_init_from_array(d1, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv1d(bias=0): ");
	tensor_print(conv1d(a, b, 0.0));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[2.0000, 4.0000, 6.0000, 8.0000, 10.0000, 12.0000, 14.0000, 16.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 1, 5);
	b = tensor_init_from_array(d3, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv1d(bias=1): ");
	tensor_print(conv1d(a, b, 1));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[[ 7.0000,  3.0000, -4.0000, -8.0000]]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(1, 3);
	b = tensor_init_random(1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv1d(bias=0.3): ");
	tensor_print(conv1d(a, b, 0.3));
	tensor_free(a);
	tensor_free(b);

	return (0);
}
