#include "linalg.h"
#include "tensor.h"
#include "ops.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {0, 10, 0};
	float		d1[] = {10, 0, 0, 0, 10, 0, 0, 0, 10, 0, 0, 10};
	float		d2[] = {1, 0, 10, 0, 100, 5, 1000, 6};

	struct Tensor	*q = tensor_init_from_array(d0, 1, 3);
	struct Tensor	*k = tensor_init_from_array(d1, 4, 3);
	struct Tensor	*v = tensor_init_from_array(d2, 4, 2);

	tensor_print(q);
	tensor_print(k);
	tensor_print(v);
	printf("\n>>> scaled dot-product attention:\n");
	tensor_print(sdpa(q, transpose(k), v));

// expected : tensor([[10.0000, 0.0000]])

	printf("\n---------------------------------------------\n");
	q = tensor_init_random(1, 8);
	k = tensor_init_random(3, 8);
	v = tensor_init_random(3, 3);
	tensor_print(q);
	tensor_print(k);
	tensor_print(v);
	printf("\n>>> scaled dot-product attention:\n");
	tensor_print(sdpa(q, transpose(k), v));

	return (0);
}
