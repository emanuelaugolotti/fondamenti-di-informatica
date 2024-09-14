#include "matrix.h"

double calcolo_norma(const struct matrix* mat, size_t i) {
	double norma;
	double somma = 0;
	for (size_t c = 0; c < mat->cols; ++c) {
		somma += pow(mat->data[i * mat->cols + c], 2);
	}
	norma = sqrt(somma);
	return norma;
}

struct matrix* mat_normalize_rows(const struct matrix* m)
{
	if (m == NULL) {
		return NULL;
	}
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows;
	out->cols = m->cols;
	out->data = malloc(out->rows * out->cols * sizeof(double));
	for (size_t r = 0; r < m->rows; ++r) {
		double norma = calcolo_norma(m, r);
		if (norma == 0) {
			norma = 1;
		}
		for (size_t c = 0; c < m->cols; ++c) {
			out->data[r * out->cols + c] = m->data[r * m->cols + c] / norma;
		}
	}
	return out;
}