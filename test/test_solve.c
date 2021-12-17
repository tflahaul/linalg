// cc test/test_solve.c -I include linalg.a

#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {3, 8, 4, 11};
	float		d1[] = {5, 7};

	float		d2[] = {1, 1, 1, 0, 2, 5, 2, 5, -1};
	float		d3[] = {6, -4, 27};

	struct Tensor	*a = tensor_init_from_array(d0, 2, 2);
	struct Tensor	*b = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> system solution:\n");
	tensor_print(solve(a, b));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[-1.0000, 1.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 3, 3);
	b = tensor_init_from_array(d3, 1, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> system solution:\n");
	tensor_print(solve(a, b));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[5.0000, 3.0000, -2.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_constant(3, 3, 1.0);
	b = tensor_init_constant(1, 3, 1.0);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> system solution:\n");
	tensor_print(solve(a, b));
	tensor_free(a);
	tensor_free(b);

// expected : error because of singular matrix

	return (0);
}
