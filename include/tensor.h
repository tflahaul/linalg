#ifndef __TENSOR_H__
#define __TENSOR_H__

#include <stdint.h>

#define MAX_SUPPORTED_DIMS 2

struct Tensor {
	uint32_t	shape[MAX_SUPPORTED_DIMS];
	float		*data;
};

#define TENSOR_NUMEL(x)	((x)->shape[0] * (x)->shape[1])

struct Tensor	*tensor_init(uint32_t const n, uint32_t const m);
struct Tensor	*tensor_init_random(uint32_t const n, uint32_t const m);
struct Tensor	*tensor_init_constant(uint32_t const n, uint32_t const m, float const x);
struct Tensor	*tensor_init_from_array(float const *data, uint32_t const n, uint32_t const m);
struct Tensor	*tensor_init_from_tensor(struct Tensor const *src);
struct Tensor	*tensor_init_eye(uint32_t const size);

void		tensor_print(struct Tensor const *tensor);
void		tensor_free(struct Tensor *tensor);

#endif /* __TENSOR_H__ */
