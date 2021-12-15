#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {1, -2, -1, 2};
	float		d1[] = {1, 2, 3, 4, 5, 6};

	struct Tensor	*a = tensor_init_from_array(d0, 2, 2);
	tensor_print(a);
	printf("\n>>> transpose:\n");
	tensor_print(transpose(a));
	tensor_free(a);

// expected : tensor([[ 1.0000, -1.0000],
//	              [-2.0000,  2.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 2, 3);
	tensor_print(a);
	printf("\n>>> transpose:\n");
	tensor_print(transpose(a));
	tensor_free(a);

// expected : tensor([[1.0000, 4.0000],
//                    [2.0000, 5.0000],
//                    [3.0000, 6.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(5, 2);
	tensor_print(a);
	printf("\n>>> transpose:\n");
	tensor_print(transpose(a));
	tensor_free(a);

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(1, 5);
	tensor_print(a);
	printf("\n>>> transpose:\n");
	tensor_print(transpose(a));
	tensor_free(a);

	return (0);
}
