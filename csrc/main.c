#include "tensor.h"
#include "linalg.h"

#include <stdio.h>

int			main(void) {
	float		data[] = {0.9624, 0.3576, 0.3314, 0.0830, 0.6321, 0.9403, 0., 0., 0.}; // 0.8249, 0.4797, 0.6575
	struct Tensor	*a;

	a = tensor_init_from_array(data, 3, 3);
	tensor_print(a);
	printf("\n");
	tensor_print(inverse(a));
	tensor_free(a);
	return (0);
}
