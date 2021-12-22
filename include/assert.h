#ifndef __ASSERT_H__
#define __ASSERT_H__

#include "tensor.h"

#include <stdlib.h> // needed for exit
#include <stdio.h> // for fprintf
#include <math.h> // for fabsf

#define S_MEM_FAIL	"failed to allocate new tensor"
#define S_BROAD_ERR	"tensors are not broadcastable"
#define S_VEC_ERR	"tensor is not a vector"
#define S_SQUARE_ERR	"tensor is not a square matrix"
#define S_DIM_ERR	"unexpected dimension in tensor"
#define S_MM_ERR	"tensors cannot be multiplied"
#define S_INV_ERR	"tensor is singular and thus not invertible"
#define S_CONV_KER_ERR	"kernel size is greater than input size"
#define S_STRIDE_ERR	"stride value is zero"

static inline void	assert(int x, char const *msg, char const *file, int line) {
	if (__builtin_expect((x == 0), 0)) {
		fprintf(stderr, "error: %s:%i -> %s\n", file, line, msg);
		exit(EXIT_FAILURE);
	}
}

static inline int	invertible(struct Tensor *a) {
	for (uint32_t index = 0; index < a->shape[0]; index++)
		if (fabsf(a->data[(index * a->shape[1]) + index]) < 1e-8)
			return (0);
	return (1);
}

#define	__assert_non_null(p)		{assert(((p) != NULL), S_MEM_FAIL, __FILE__, __LINE__);}
#define __assert_broadcastable(a, b)	{assert(((a)->shape[0] == (b)->shape[0]) && ((a)->shape[1] == (b)->shape[1]), S_BROAD_ERR, __FILE__, __LINE__);}
#define __assert_tensor_is_vector(a)	{assert(((a)->shape[0] == 1) || ((a)->shape[1] == 1), S_VEC_ERR, __FILE__, __LINE__);}
#define __assert_tensor_is_square(a)	{assert(((a)->shape[0] == (a)->shape[1]), S_SQUARE_ERR, __FILE__, __LINE__);}
#define __assert_tensor_has_dim(a, x)	{assert(((a)->shape[0] == x || (a)->shape[1] == x), S_DIM_ERR, __FILE__, __LINE__);}
#define __assert_tensor_mm_able(a, b)	{assert((a->shape[1] == b->shape[0]), S_MM_ERR, __FILE__, __LINE__);}
#define __assert_tensor_invertible(a)	{assert(invertible(a), S_INV_ERR, __FILE__, __LINE__);}
#define __assert_conv1d_size(a, b)	{assert(((a)->shape[1] >= (b)->shape[1]), S_CONV_KER_ERR, __FILE__, __LINE__);}
#define __assert_non_zero_stride(a)	{assert((a > 0), S_STRIDE_ERR, __FILE__, __LINE__);}

#endif /* __ASSERT_H__ */
