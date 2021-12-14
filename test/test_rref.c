#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {1, 2, 3, 4};
	float		d1[] = {1, 2, 2, 4};
	float		d2[] = {8, 5, -2, 4, 28, 4, 2.5, 20, 4, -4, 8, 5, 1, 4, 17};

	struct Tensor	*a = tensor_init_from_array(d0, 2, 2);
	tensor_print(a);
	printf("\n>>> rref\n");
	tensor_print(rref_(a));
	tensor_free(a);

// expected :  tensor([[1.0000, 0.0000],
//                     [0.0000, 1.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 2, 2);
	tensor_print(a);
	printf("\n>>> rref\n");
	tensor_print(rref_(a));
	tensor_free(a);

// expected :  tensor([[1.0000, 2.0000],
//                     [0.0000, 0.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 3, 5);
	tensor_print(a);
	printf("\n>>> rref\n");
	tensor_print(rref_(a));
	tensor_free(a);

// expected :  tensor([[ 1.0000,  0.6250,  0.0000, 0.0000, -12.1667],
//                     [ 0.0000,  0.0000,  1.0000, 0.0000,  -3.6667],
//                     [-0.0000, -0.0000, -0.0000, 1.0000,  29.5000]])

	return (0);
}
