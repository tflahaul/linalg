#ifndef __LINALG_H__
#define __LINALG_H__

#include "tensor.h"

struct Tensor	*linear_combination(struct Tensor *a, struct Tensor *b);

struct Tensor	*lerp(struct Tensor *a, struct Tensor *b, f32_t k);

struct Tensor	*cross(struct Tensor *a, struct Tensor *b);

struct Tensor	*mm(struct Tensor *a, struct Tensor *b);

struct Tensor	*transpose(struct Tensor *a);

struct Tensor	*rref(struct Tensor *a);

f32_t		dot(struct Tensor *a, struct Tensor *b);

f32_t		norm(struct Tensor *a);

f32_t		norm_1(struct Tensor *a);

f32_t		norm_inf(struct Tensor *a);

f32_t		angle(struct Tensor *a, struct Tensor *b);

f32_t		trace(struct Tensor *a);

uint32_t	rank(struct Tensor *a);

#endif /* __LINALG_H__ */
