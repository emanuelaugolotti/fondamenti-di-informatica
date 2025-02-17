#if !defined MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* mat_delete_col(const struct matrix* m, size_t i);

#endif /* MATRIX_H */