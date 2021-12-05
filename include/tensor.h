#ifndef __TENSOR_H__
#define __TENSOR_H__

#include <stdint.h>

#define MAX_SUPPORTED_DIMS 2

#ifndef NULL
# define NULL (void *)0
#endif /* NULL */

struct Tensor {
	uint32_t	shape[MAX_SUPPORTED_DIMS];
	float		*data;
};

#define TENSOR_NUMEL(x)	((x)->shape[0] * (x)->shape[1])

struct Tensor	*tensor_init(uint32_t n, uint32_t m);
struct Tensor	*tensor_init_random(uint32_t n, uint32_t m);
struct Tensor	*tensor_init_constant(uint32_t n, uint32_t m, float x);
struct Tensor	*tensor_init_from_array(float *data, uint32_t r, uint32_t c);
struct Tensor	*tensor_init_from_tensor(struct Tensor *src);

void		tensor_print(struct Tensor *tensor);
void		tensor_free(struct Tensor *tensor);

#endif /* __TENSOR_H__ */
