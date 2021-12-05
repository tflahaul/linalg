#include "tensor.h"
#include "linalg.h"

float		angle(struct Tensor *a, struct Tensor *b) {
	return (dot(a, b) / (norm(a) * norm(b)));
}
