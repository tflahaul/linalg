#include "tensor.h"
#include "ops.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {-8, 1, 7, 3, 9, -67, 1, 4, 0};

	struct Tensor	*a = tensor_init_from_array(d0, 3, 3);
	tensor_print(a);
	printf("\n>>> flatten: ");
	tensor_print(flatten_(a));
	tensor_free(a);

// expected : tensor([[-8.0000, 1.0000, 7.0000, 3.0000, 9.0000, -67.0000, 1.0000, 4.0000, 0.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(5, 3);
	tensor_print(a);
	printf("\n>>> flatten: ");
	tensor_print(flatten(a));
	tensor_free(a);

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(1, 5);
	tensor_print(a);
	printf("\n>>> flatten: ");
	tensor_print(flatten_(a));
	tensor_free(a);

	return (0);
}
