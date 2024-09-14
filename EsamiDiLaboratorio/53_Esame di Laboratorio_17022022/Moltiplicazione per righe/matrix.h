#if !defined MATRIX_H
#define MATRIX_H

#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    double* data;
};

#define Elemento(m, r, c) (m)->data[(r) * m->cols + (c)]

extern struct matrix* mat_rowmul(const struct matrix* m1, const struct matrix* m2);

#endif