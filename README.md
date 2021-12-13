# linalg

Linear algebra C library (with tensors)

### ops

```
add, sub, scl      # binary ops
relu               # unary ops
```

### linalg

Library includes 17 linear algebra functions :

```
linear_combination # linear combination of a tensor and a vector of scalars
lerp               # linear interpolation of two tensors based on a scalar
dot                # dot product of two given VECTORS
norm_1             # manhattan norm
norm               # euclidean norm
norm_inf           # supremum norm
angle              # cosine of the angle between two given vectors
cross              # cross product of two tensors both of shape nx3
mm                 # matrix multiplication
trace              # returns the trace of a square matrix
transpose          # flips a tensor over its diagonal
flip               # mirrors a tensor
ref                # returns the row echelon form of the given matrix
rref               # returns the reduced row echelon form of the given matrix
rank               # rank of the matrix
det                # computes the determinant of a square matrix
inverse            # returns the inverse of a non-singular square matrix
```
