#if !defined MATRIX_H
#define MATRIX_H

#include <stdlib.h>

#define Elemento(m,r,c) (m)->data[(r) * m->cols + (c)] //Definisco la macro elemento

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* matrix_flip_v(const struct matrix* m);

#endif /* MATRIX_H */