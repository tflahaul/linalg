#include "tensor.h"
#include "linalg.h"
#include "ops.h"

#include <stdio.h>

int			main(void) {
	struct Tensor	*a;
	struct Tensor	*b = tensor_init_constant(50, 50, 0.5);

	a = sub(tensor_init_random(50, 50), b);

	float out = det(a);
	printf("det = %f\n", out);
	tensor_free(a);
	tensor_free(b);
	return (0);
}
