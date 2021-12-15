#include "linalg.h"
#include "tensor.h"

#include <stdio.h>

int			main(void) {
	float		d0[] = {0, 4, 2, 8, 1, 0, 6, 5, 4};

	struct Tensor	*a = tensor_init_from_array(d0, 3, 3);
	tensor_print(a);
	printf(">>> trace: %f\n", trace(a));
	tensor_free(a);

// expected : 5.0

	printf("\n---------------------------------------------\n");
	a = tensor_init_constant(3, 3, -1.0);
	tensor_print(a);
	printf(">>> trace: %f\n", trace(a));
	tensor_free(a);

// expected : -3.0

	return (0);
}
