#ifndef __ASSERT_H__
#define __ASSERT_H__

#include "tensor.h"

void	assert_tensor_broadcastable(struct Tensor *a, struct Tensor *b);
void	assert_tensor_is_vector(struct Tensor *a);
void	assert_tensor_is_square(struct Tensor *a);
void	assert_tensor_has_dim(struct Tensor *a, uint32_t dim);
void	assert_tensor_mm_able(struct Tensor *a, struct Tensor *b);
void	assert_non_zero_determinant(struct Tensor *a);

#endif /* __ASSERT_H__ */
