#include "../include/tensor.h"
#include "../include/ops.h"
#include "../include/linalg.h"

#include <stdio.h>

int 			main(void) {
	struct Tensor	*a = tensor_rand_init(15, 100);

	printf("%f\n", norm(a));

	tensor_free(a);
	return (0);
}
