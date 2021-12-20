#ifndef __LINALG_H__
#define __LINALG_H__

#include "tensor.h"

struct Tensor	*linear_combination(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*lerp(struct Tensor *lhs, struct Tensor *rhs, float k);
struct Tensor	*cross(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*outer(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*mm(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*transpose(struct Tensor *tensor);
struct Tensor	*ref(struct Tensor *tensor);
struct Tensor	*ref_(struct Tensor *tensor);
struct Tensor	*rref(struct Tensor *tensor);
struct Tensor	*rref_(struct Tensor *tensor);
struct Tensor	*inverse(struct Tensor *tensor);
struct Tensor	*inverse_(struct Tensor *tensor);
struct Tensor	*flip(struct Tensor *tensor);
struct Tensor	*solve(struct Tensor *lhs, struct Tensor *rhs);
float		dot(struct Tensor *lhs, struct Tensor *rhs);
float		norm(struct Tensor *tensor);
float		norm_1(struct Tensor *tensor);
float		norm_inf(struct Tensor *tensor);
float		angle(struct Tensor *lhs, struct Tensor *rhs);
float		trace(struct Tensor *tensor);
float		det(struct Tensor *tensor);
uint32_t	rank(struct Tensor *tensor);

#endif /* __LINALG_H__ */
