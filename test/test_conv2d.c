#include "tensor.h"
#include "ops.h"

#include <stdio.h>

int			main(void) {
	float		k0[] = {0.7320, 0.2174, 0.5368, 0.1807};
	float		d0[] = {0.6106, 0.3013, 0.9941, 0.5446, 0.6236,
				0.7598, 0.7691, 0.3985, 0.7564, 0.5157,
				0.6587, 0.0278, 0.8874, 0.4383, 0.7772,
				0.5226, 0.1633, 0.6627, 0.6965, 0.2520,
				0.1100, 0.6833, 0.1920, 0.3058, 0.3759};
	float		k1[] = {-.5, .5, -.5, .5,  1., .5, -.5, .5, -.5};
	float		d1[] = {2, 5, 1, 8, 5, 6, 7, 1, -3, 5, 0, 4};
	float		k2[] = {0, 1, 1, 0};

	struct Tensor	*a = tensor_init_from_array(d0, 5, 5);
	struct Tensor	*b = tensor_init_from_array(k0, 2, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv2d(bias=0, stride=1):\n");
	tensor_print(conv2d(a, b, 0, 1));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[[[1.0593, 0.9215, 1.1967, 1.0334],
//                      [1.0820, 0.8249, 1.0117, 1.0415],
//                      [0.7983, 0.4207, 1.2265, 0.9092],
//                      [0.6006, 0.6651, 0.7948, 0.7967]]]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_from_array(d1, 4, 3);
	b = tensor_init_from_array(k1, 3, 3);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv2d(bias=1, stride=1):\n");
	tensor_print(conv2d(a, b, 1, 1));
	tensor_free(a);
	tensor_free(b);

// expected : tensor([[12.5000],
//                    [-5.0000]])

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(10, 5);
	b = tensor_init_from_array(k2, 2, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv2d(bias=2, stride=2):\n");
	tensor_print(conv2d(a, b, 2, 2));
	tensor_free(a);
	tensor_free(b);

	printf("\n---------------------------------------------\n");
	a = tensor_init_random(6, 6);
	b = tensor_init_from_array(k2, 2, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv2d(bias=0, stride=1):\n");
	tensor_print(conv2d(a, b, 0, 1));
	tensor_free(a);
	tensor_free(b);

	printf("\n---------------------------------------------\n");
	a = scl_(tensor_init_random(3, 3), 100);
	b = tensor_init_random(2, 2);
	tensor_print(a);
	tensor_print(b);
	printf("\n>>> conv2d(bias=0, stride=8):\n");
	tensor_print(conv2d(a, b, 0, 8));
	tensor_free(a);
	tensor_free(b);

	return (0);
}
