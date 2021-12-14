#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	float		d1[] = {2, 0, 0, 0, 2, 0, 0, 0, 2};
	float		d2[] = {8, 5, -2, 4, 7, 20, 7, 6, 1};

	struct Tensor	*a = tensor_init_from_array(d0, 3, 3);
	tensor_print(a);
	printf("\n>>> inverse:\n");
	tensor_print(inverse(a));
	tensor_free(a);

// expected :   tensor([[1.0000, 0.0000, 0.0000],
//	                [0.0000, 1.0000, 0.0000],
//	                [0.0000, 0.0000, 1.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 3, 3);
	tensor_print(a);
	printf("\n>>> inverse:\n");
	tensor_print(inverse(a));
	tensor_free(a);

// expected :   tensor([[0.5000, 0.0000, 0.0000],
//	                [0.0000, 0.5000, 0.0000],
//	                [0.0000, 0.0000, 0.5000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 3, 3);
	tensor_print(a);
	printf("\n>>> inverse:\n");
	tensor_print(inverse(a));
	tensor_free(a);

// expected :   tensor([[ 0.6494,  0.0977, -0.6552],
//                      [-0.7816, -0.1264,  0.9655],
//	                [ 0.1437,  0.0747, -0.2069]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_constant(3, 3, 1.0);
	tensor_print(a);
	printf("\n>>> inverse:\n");
	tensor_print(inverse(a));
	tensor_free(a);

// expected :   error because of singularity

	return (0);
}
