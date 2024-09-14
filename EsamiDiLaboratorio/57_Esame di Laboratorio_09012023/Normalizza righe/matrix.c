#include "matrix.h"

double calcolo_norma(struct matrix *mat, size_t riga)
{
	double norma2 = 0;
	for (size_t c = 0; c < mat->cols; ++c) {
		norma2 += pow(mat->data[riga * mat->cols + c], 2);
	}
	double norma = sqrt(norma2);
	return norma;
}

void mat_normalize_rows(struct matrix* m)
{
	if (m == NULL) {
		return;
	}
	for (size_t r = 0; r < m->rows; ++r) {
		double norma = calcolo_norma(m, r);
		if (norma != 0) {
			for (size_t c = 0; c < m->cols; ++c) {
				m->data[r * m->cols + c] /= norma;
			}
		}
	}
	return;
}