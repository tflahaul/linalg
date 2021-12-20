// cc test_det.c -I include linalg.a

#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {1, -1, -1, 1};
	float d1[] = {2, 0, 0, 0, 2, 0, 0, 0, 2};
	float d2[] = {8, 5, -2, 4, 7, 20, 7, 6, 1};
	float d3[] = {8, 5, -2, 4, 4, 2.5, 20, 4, 8, 5, 1, 4, 28, -4, 17, 1};

	struct Tensor *a = tensor_init_from_array(d0, 2, 2);
	tensor_print(a);
	printf("\n>>> det: %.3f\n", det(a));
	tensor_free(a);

// expected :  0.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 3, 3);
	tensor_print(a);
	printf("\n>>> det: %.3f\n", det(a));
	tensor_free(a);

// expected : 8.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 3, 3);
	tensor_print(a);
	printf("\n>>> det: %.3f\n", det(a));
	tensor_free(a);

// expected : -174.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d3, 4, 4);
	tensor_print(a);
	printf("\n>>> det: %.3f\n", det(a));
	tensor_free(a);

// expected : 1032.0

	return (0);
}
