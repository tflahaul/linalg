#include "tensor.h"
#include "linalg.h"

f32_t		angle(struct Tensor *a, struct Tensor *b) {
	return (dot(a, b) / (norm(a) * norm(b)));
}
