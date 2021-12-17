#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	float		d1[] = {1, 2, 0, 0, 2, 4, 0, 0, -1, 2, 1, 1};
	float		d2[] = {8, 5, -2, 4, 7, 20, 7, 6, 1, 21, 18, 7};

	struct Tensor	*a = tensor_init_from_array(d0, 3, 3);
	tensor_print(a);
	printf("\n>>> rank: %u\n", rank(a));

// expected : 3

	printf("\n---------------------------------------------\n");
	a->data[TENSOR_NUMEL(a) - 1] = 0.0;
	tensor_print(a);
	printf("\n>>> rank: %u\n", rank(a));
	tensor_free(a);

// expected : 2

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 3, 4);
	tensor_print(a);
	printf("\n>>> rank: %u\n", rank(a));
	tensor_free(a);

// expected : 2

	printf("\n---------------------------------------------\n");
	a = tensor_init_constant(5, 5, 1.0);
	tensor_print(a);
	printf("\n>>> rank: %u\n", rank(a));
	tensor_free(a);

// expected : 1

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 4, 3);
	tensor_print(a);
	printf("\n>>> rank: %u\n", rank(a));
	tensor_free(a);

// expected : 3

	return (0);
}
