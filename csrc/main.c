#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int			main(void) {
	struct Tensor	*a;
	float data[] = {2.0, 1.0, 1.0, 1.0, 0.5, 1.0, 0.0, 1.0, 1.0};

	a = tensor_init_from_array(data, 3, 3);
	tensor_print(a);
	printf("det: %f\n\n", det(a));
	tensor_free(a);

	a = tensor_init_random(4, 4);
	tensor_print(a);
	printf("det: %f\n", det(a));
	tensor_free(a);
	return (0);
}
