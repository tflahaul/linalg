#include "tensor.h"
#include "ops.h"

#include <stdio.h>

int			main(void) {
	struct Tensor	*a = tensor_init_random(3, 3);
	tensor_print(a);
	printf("\n>>> pad(0, 1, 0):\n");
	tensor_print(pad(a, 0, 1, 0));

	printf("\n---------------------------------------------\n");
	tensor_print(a);
	printf("\n>>> pad(1, 0, 0):\n");
	tensor_print(pad(a, 1, 0, 0));

	printf("\n---------------------------------------------\n");
	tensor_print(a);
	printf("\n>>> pad(1, 1, 0):\n");
	tensor_print(pad(a, 1, 1, 0));

	printf("\n---------------------------------------------\n");
	tensor_print(a);
	printf("\n>>> pad(0, 2, 0):\n");
	tensor_print(pad(a, 0, 2, 0));
	tensor_free(a);

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(5, 1);
	tensor_print(a);
	printf("\n>>> pad(0, 1, 0):\n");
	tensor_print(pad(a, 0, 1, 0));

	printf("\n---------------------------------------------\n");
	a = flatten_(a);
	tensor_print(a);
	printf("\n>>> pad(0, 1, 0):\n");
	tensor_print(pad(a, 0, 1, 0));
	tensor_free(a);

	return (0);
}
