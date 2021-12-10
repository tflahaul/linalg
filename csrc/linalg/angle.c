#include "tensor.h"
#include "linalg.h"

float		angle(struct Tensor *lhs, struct Tensor *rhs) {
	return (dot(lhs, rhs) / (norm(lhs) * norm(rhs)));
}
