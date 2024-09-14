#include "matrix.h"

struct matrix* matrix_flip_v(const struct matrix* m)
{
	if (m == NULL) {
		return NULL;
	}

	struct matrix* mat_ribaltata = malloc(sizeof(struct matrix));
	mat_ribaltata->rows = m->rows;
	mat_ribaltata->cols = m->cols;
	mat_ribaltata->data = malloc(m->rows * m->cols * sizeof(double));

	for (size_t r = 0; r < mat_ribaltata->rows; ++r) {
		for (size_t c = 0; c < mat_ribaltata->cols; ++c) {
			Elemento(mat_ribaltata, r, c) = Elemento(m, (m->rows) - 1 - r, c);
		}
	}
	
	return mat_ribaltata;
}