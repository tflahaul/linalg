#include "linalg.h"
#include "tensor.h"
#include <stdio.h>
#include <time.h>

int			main(void) {
	struct Tensor	*a = tensor_init_random(4096, 4096);
	struct Tensor	*b = tensor_init_random(4096, 4096);
	struct Tensor	*c;
	clock_t		start, end;

	start = clock();
	c = mm(a, b);
	end = clock();
	tensor_free(c);

	printf("time=%f\n", difftime(end, start)/CLOCKS_PER_SEC);
	return (0);
}
