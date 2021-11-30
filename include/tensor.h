#ifndef __TENSOR_H__
#define __TENSOR_H__

#include <stdint.h>

#define SUPPORTED_DIMS	2

typedef float f32_t;
 
struct Tensor {
	uint32_t	shape[SUPPORTED_DIMS];
	f32_t		*data;
};

#define TENSOR_ISVEC(x)	((x)->shape[1] == 1 || (x)->shape[0] == 1)
#define TENSOR_NUMEL(x)	((x)->shape[0] * (x)->shape[1])
#define TENSOR_SQUARE(x)((x)->shape[0] == (x)->shape[1])

struct Tensor		*tensor_init(uint32_t n, uint32_t m);
struct Tensor		*tensor_rand_init(uint32_t n, uint32_t m);
struct Tensor		*tensor_constant_init(uint32_t n, uint32_t m, f32_t x);

void			tensor_print(struct Tensor *tensor);
void			tensor_free(struct Tensor *tensor);

#endif /* __TENSOR_H__ */
