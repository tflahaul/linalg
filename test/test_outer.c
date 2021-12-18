#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {1, 2, 3};
	float		d1[] = {0, 1, 0};

	float		d2[] = {1, 2, 3, 4, 5};

	struct Tensor	*a = tensor_init_from_array(d0, 1, 3);
	struct Tensor	*b = tensor_init_from_array(d1, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> outer product:\n");
	tensor_print(outer(a, b));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[0.0000, 1.0000, 0.0000],
//		      [0.0000, 2.0000, 0.0000],
//		      [0.0000, 3.0000, 0.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 1, 5);
	b = tensor_init_from_array(d0, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> outer product:\n");
	tensor_print(outer(a, b));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[1.0000,  2.0000,  3.0000],
//		      [2.0000,  4.0000,  6.0000],
//		      [3.0000,  6.0000,  9.0000],
//		      [4.0000,  8.0000, 12.0000],
//		      [5.0000, 10.0000, 15.0000]])

	return (0);
}
