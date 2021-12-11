#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {0, 0, 1};
	float d1[] = {1, 0, 0};

	float d2[] = {1, 2, 3};
	float d3[] = {4, 5, 6};

	float d4[] = {4, 2, -3};
	float d5[] = {-2, -5, 16};

	struct Tensor *a = tensor_init_from_array(d0, 1, 3);
	struct Tensor *b = tensor_init_from_array(d0, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> cross: ");
	tensor_print(cross(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[0.0000, 0.0000, 0.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 1, 3);
	b = tensor_init_from_array(d3, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> cross: ");
	tensor_print(cross(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[-3.0000, 6.0000, -3.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d4, 1, 3);
	b = tensor_init_from_array(d5, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> cross: ");
	tensor_print(cross(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[17.0000, -58.0000, -16.0000]])

	return (0);
}
