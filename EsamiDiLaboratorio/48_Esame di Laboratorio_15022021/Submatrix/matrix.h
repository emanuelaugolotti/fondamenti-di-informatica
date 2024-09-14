#if !defined MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* mat_submatrix(const struct matrix* mat, const int* row_idxs, const int* col_idxs);

#endif /* MATRIX_H */