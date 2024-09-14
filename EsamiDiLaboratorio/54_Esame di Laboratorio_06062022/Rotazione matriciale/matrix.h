#if !defined MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#define Elemento(m,r,c) (m)->data[(r) * (m)->cols + (c)]

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* mat_rotate180(const struct matrix* m);

#endif  /* MATRIX_H */