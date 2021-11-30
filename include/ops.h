#ifndef __OPS_H__
#define __OPS_H__

#include "tensor.h"

struct Tensor		*add(struct Tensor *a, struct Tensor *b);
struct Tensor		*sub(struct Tensor *a, struct Tensor *b);
struct Tensor		*mul(struct Tensor *a, struct Tensor *b);
struct Tensor		*scl(struct Tensor *a, f32_t f);

#endif /* __OPS_H__ */
