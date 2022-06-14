#include "linalg.h"
#include "tensor.h"
#include "ops.h"

#include <stdio.h>
#include <time.h>

int			main(void) {
	struct Tensor	*a = tensor_init_random(2048, 2048);
	struct Tensor	*b = tensor_init_random(512, 512);
	struct Tensor	*c;
	clock_t		start, end;

	start = clock();
	c = conv2d(a, b, 0, 1);
	end = clock();

	tensor_free(c);
	printf("time=%f\n", difftime(end, start)/CLOCKS_PER_SEC);
	return (0);
}
