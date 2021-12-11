// cc test_dot.c -I include linalg.a

#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {-1, 6};
	float d1[] = {3, 2};

	struct Tensor *a = tensor_init_constant(1, 2, 0.0);
	struct Tensor *b = tensor_init_constant(1, 2, 1.0);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> dot: %f\n", dot(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  0.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_constant(1, 2, 1.0);
	b = tensor_init_constant(1, 2, 1.0);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> dot: %f\n", dot(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :   2.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d0, 1, 2);
	b = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> dot: %f\n", dot(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :   9.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(1, 2);
	b = tensor_init_random(2, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> dot: %f\n", dot(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  error because b is not a vector

	return (0);
}
