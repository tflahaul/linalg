#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {0.6001, 0.2069, -0.1919, 0.9792, 0.6727, 1.0062, 0.4126, -0.2129, -0.4206, 0.1968};
	float		d1[] = {1, 1, 1, 0, 1, 1, 1};
	float		d2[] = {3, 2, 0, -1, 6, 5, 1, 8, 5, 0};

	struct Tensor	*a = tensor_init_from_array(d0, 1, 10);
	tensor_print(a);
	printf("\n>>> cumprod: ");
	tensor_print(cumprod(a));
	tensor_free(a);

// expected : tensor([ 0.6001,  0.1241, -0.0238, -0.0233, -0.0157, -0.0158, -0.0065,  0.0014, -0.0006, -0.0001])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 1, 7);
	tensor_print(a);
	printf("\n>>> cumprod: ");
	tensor_print(cumprod(a));
	tensor_free(a);

// expected : tensor([1.0000, 1.0000, 1.0000, 0.0000, 0.0000, 0.0000, 0.0000])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 2, 5);
	tensor_print(a);
	printf("\n>>> cumprod:\n");
	tensor_print(cumprod(a));
	tensor_free(a);

// expected : tensor([[3.0000, 6.0000,  0.0000,  -0.0000, -0.0000],
//		      [5.0000, 5.0000, 40.0000, 200.0000,  0.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(5, 8);
	tensor_print(a);
	printf("\n>>> cumprod:\n");
	tensor_print(cumprod(a));
	tensor_free(a);

	return (0);
}
