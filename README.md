# linalg
### linear_combination
```struct Tensor *linear_combination(struct Tensor *a, struct Tensor *coefs);```<br/>
Linear combination of the matrix `a` and `coefs`, a vector of scalars.<br/>

### lerp
```struct Tensor *lerp(struct Tensor *a, struct Tensor *b, float k);```<br/>
Linear interpolation of the `a` and `b` matrices based on `k`, a scalar.<br/>

### dot
```float dot(struct Tensor *a, struct Tensor *b);```<br/>
Dot product of two given vectors. Different than numpy's dot or python @ operator.<br/>

### norms
```float norm_1(struct Tensor *a);```<br/>
```float norm(struct Tensor *a);```<br/>
```float norm_inf(struct Tensor *a);```<br/>
Functions to compute different kinds of norms on a given vector.

### angle
```float angle(struct Tensor *a, struct Tensor *b);```<br/>
Returns the cosine of the angle between the two given vectors.

### cross
```struct Tensor *cross(struct Tensor *a, struct Tensor *b);```<br/>
Returns the cross product of `a` and `b`.<br/>

### mm
```struct Tensor *mm(struct Tensor *a, struct Tensor *b);```<br/>
Matrix multiplication. Similar to numpy's dot or python @ operator.

### trace
```float trace(struct Tensor *a);```<br/>
Returns the trace of the given square matrix.

### transpose
```struct Tensor *transpose(struct Tensor *a);```<br/>
Flips `a` over it's diagonal.

### rref
```struct Tensor *rref(struct Tensor *a);```<br/>
Returns the reduced row echelon form of the given matrix.

### rref_
```struct Tensor *rref_(struct Tensor *a);```<br/>
`rref` but in-place.

### rank
```unsigned int rank(struct Tensor *a);```<br/>
Returns the rank of the given matrix.

### det
```float det(struct Tensor *a);```<br/>
Returns the determinant of the given square matrix.

### inverse
```struct Tensor *inverse(struct Tensor *a);```<br/>
If the given matrix is invertible, returns its inverse.
