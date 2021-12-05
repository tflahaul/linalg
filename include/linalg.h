#ifndef __LINALG_H__
#define __LINALG_H__

#include "tensor.h"

struct Tensor	*linear_combination(struct Tensor *a, struct Tensor *b);

struct Tensor	*lerp(struct Tensor *a, struct Tensor *b, float k);

struct Tensor	*cross(struct Tensor *a, struct Tensor *b);

struct Tensor	*mm(struct Tensor *a, struct Tensor *b);

struct Tensor	*transpose(struct Tensor *a);

struct Tensor	*rref(struct Tensor *a);

struct Tensor	*inverse(struct Tensor *a);

float		dot(struct Tensor *a, struct Tensor *b);

float		norm(struct Tensor *a);

float		norm_1(struct Tensor *a);

float		norm_inf(struct Tensor *a);

float		angle(struct Tensor *a, struct Tensor *b);

float		trace(struct Tensor *a);

float		det(struct Tensor *a);

uint32_t	rank(struct Tensor *a);

#endif /* __LINALG_H__ */
