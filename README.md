# linalg
### linear_combination
```struct Tensor *linear_combination(struct Tensor *lhs, struct Tensor *rhs);```<br/>
Linear combination of the matrix `a` and `coefs`, a vector of scalars.<br/>

### lerp
```struct Tensor *lerp(struct Tensor *lhs, struct Tensor *rhs, float k);```<br/>
Linear interpolation of the `a` and `b` matrices based on `k`, a scalar.<br/>

### dot
```float dot(struct Tensor *lhs, struct Tensor *rhs);```<br/>
Dot product of two given vectors. Different than numpy's dot or python @ operator.<br/>

### norms
```float norm_1(struct Tensor *tensor);```<br/>
```float norm(struct Tensor *tensor);```<br/>
```float norm_inf(struct Tensor *tensor);```<br/>
Functions to compute different kinds of norms on a given vector.

### angle
```float angle(struct Tensor *lhs, struct Tensor *rhs);```<br/>
Returns the cosine of the angle between the two given vectors.

### cross
```struct Tensor *cross(struct Tensor *lhs, struct Tensor *rhs);```<br/>
Returns the cross product of `a` and `b`.<br/>

### mm
```struct Tensor *mm(struct Tensor *lhs, struct Tensor *rhs);```<br/>
Matrix multiplication. Similar to numpy's dot or python @ operator.

### trace
```float trace(struct Tensor *tensor);```<br/>
Returns the trace of the given square matrix.

### transpose
```struct Tensor *transpose(struct Tensor *tensor);```<br/>
Flips `a` over it's diagonal.

### ref
```struct Tensor *ref(struct Tensor *tensor)```<br/>
Returns the row echelon form of the given matrix.

### ref_
```struct Tensor *ref_(struct Tensor *tensor)```<br/>
`ref` but in-place.

### rref
```struct Tensor *rref(struct Tensor *tensor);```<br/>
Returns the reduced row echelon form of the given matrix.

### rref_
```struct Tensor *rref_(struct Tensor *tensor);```<br/>
`rref` but in-place.

### rank
```unsigned int rank(struct Tensor *tensor);```<br/>
Returns the rank of the given matrix.

### det
```float det(struct Tensor *tensor);```<br/>
Returns the determinant of the given square matrix.

### inverse
```struct Tensor *inverse(struct Tensor *tensor);```<br/>
If the given matrix is invertible, returns its inverse.
