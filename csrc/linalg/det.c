#include "assert.h"
#include "tensor.h"

static float	det2x2(struct Tensor *a) {
	return (a->data[0] * a->data[3]) - (a->data[1] * a->data[2]);
}

static float	det3x3(struct Tensor *a) {
	return ((a->data[0] * ((a->data[4] * a->data[8]) - (a->data[5] * a->data[7]))) - \
		(a->data[1] * ((a->data[3] * a->data[8]) - (a->data[5] * a->data[6])) + \
		(a->data[2] * ((a->data[3] * a->data[7]) - (a->data[4] * a->data[6])))));
}

float		det(struct Tensor *a) {
	assert_tensor_is_square(a);
	if (a->shape[0] == 2)
		return (det2x2(a));
	if (a->shape[0] == 3)
		return (det3x3(a));
	return (0.);
}
