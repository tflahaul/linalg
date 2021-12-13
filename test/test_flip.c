// cc test_flip.c -I include linalg.a

#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {-1, 6, 3, 2, 7, 8};
	float d1[] = {1, 0, 0, 1};

	struct Tensor *a = tensor_init_from_array(d0, 2, 3);
	tensor_print(a);
	printf("\n>>> flip:\n");
	tensor_print(flip(a));
	tensor_free(a);

// expected :   tensor([[3.0000, 6.0000, -1.0000],
//			[8.0000, 7.0000,  2.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 2, 2);
	tensor_print(a);
	printf("\n>>> flip:\n");
	tensor_print(flip(a));
	tensor_free(a);

// expected :    tensor([[0.0000, 1.0000],
//			 [1.0000, 0.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(5, 5);
	tensor_print(a);
	printf("\n>>> flip:\n");
	tensor_print(flip(a));
	tensor_free(a);

	return (0);
}
