#ifndef __OPS_H__
#define __OPS_H__

#include "tensor.h"

struct Tensor	*add(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*sub(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*scl(struct Tensor *tensor, float f);
struct Tensor	*scl_(struct Tensor *tensor, float f);

struct Tensor	*relu(struct Tensor *tensor);
struct Tensor	*relu_(struct Tensor *tensor);
struct Tensor	*softmax(struct Tensor *tensor);
struct Tensor	*softmax_(struct Tensor *tensor);
struct Tensor	*flatten(struct Tensor *tensor);
struct Tensor	*flatten_(struct Tensor *tensor);

struct Tensor	*pad(struct Tensor *tensor, uint32_t const right, uint32_t const left, float const value);
struct Tensor	*conv1d(struct Tensor *tensor, struct Tensor *kernel, float const bias, uint32_t const stride);
struct Tensor	*conv2d(struct Tensor *tensor, struct Tensor *kernel, float const bias, uint32_t const stride);
struct Tensor	*sdpa(struct Tensor *q, struct Tensor *k, struct Tensor *v);

#endif /* __OPS_H__ */
