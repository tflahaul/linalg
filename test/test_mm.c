#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int		main(void) {
	float d0[] = {1, 0, 0, 1};
	float d1[] = {4, 2};

	float d2[] = {2, 0, 0, 2};

	float d3[] = {2, -2, -2, 2};

	float d4[] = {3, -5, 6, 8};
	float d5[] = {2, 1, 4, 2};

	struct Tensor *a = tensor_init_from_array(d0, 2, 2);
	struct Tensor *b = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> mm:\n");
	tensor_print(mm(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[4.0000, 2.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d2, 2, 2);
	b = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> mm:\n");
	tensor_print(mm(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[8.0000, 4.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d3, 2, 2);
	b = tensor_init_from_array(d1, 1, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> mm:\n");
	tensor_print(mm(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  tensor([[4.0000, -4.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d4, 2, 2);
	b = tensor_init_from_array(d5, 2, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> mm:\n");
	tensor_print(mm(a, b));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[-14.0000, -7.0000],
//		      [ 44.0000, 22.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(3, 3);
	b = tensor_init_random(3, 5);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> mm:\n");
	tensor_print(mm(a, b));
	tensor_free(a);
	tensor_free(b);

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(2, 3);
	b = tensor_init_random(3, 4);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> mm:\n");
	tensor_print(mm(a, b));
	tensor_free(a);
	tensor_free(b);

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(3, 2);
	b = tensor_init_random(3, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> mm:\n");
	tensor_print(mm(a, b));
	tensor_free(a);
	tensor_free(b);

// expected :  error because of shapes

	return (0);
}
