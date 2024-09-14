#include "matrix.h"

double* matrix_snake(const struct matrix* m)
{
	if (m == NULL) {
		return NULL;
	}
	size_t size = m->rows * m->cols;
	double* out = malloc(size * sizeof(double));
	size_t pos = 0;
	for (size_t r = 0; r < m->rows; ++r) {
		for (size_t c = 0; c < m->cols; ++c) {
			out[pos] = m->data[r * m->cols + c];
			++pos;
		}
		if (pos == size) {
			break;
		}
		++r;
		for (size_t c = 0; c < m->cols; ++c) {
			out[pos] = m->data[r * m->cols + m->cols - c - 1];
			++pos;
		}
	}
	return out;
}