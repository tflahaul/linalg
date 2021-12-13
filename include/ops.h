#ifndef __OPS_H__
#define __OPS_H__

#include "tensor.h"

struct Tensor	*add(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*sub(struct Tensor *lhs, struct Tensor *rhs);
struct Tensor	*scl(struct Tensor *tensor, float f);

struct Tensor	*relu(struct Tensor *tensor);

#endif /* __OPS_H__ */
