#if !defined MATRIX_H
#define MATRIX_H

#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    double* data;
};

//E è l'elemento della matrice m posto nella riga r e nella colonna c
#define Elemento(m, r, c) (m)->data[(r) * m->cols + (c)]

extern struct matrix* mat_scale(const struct matrix* m, double x);

#endif /* MATRIX_H */