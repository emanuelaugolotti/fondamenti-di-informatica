#include "matrix.h"

struct matrix* mirror_mat(const struct matrix* m)
{
	if (m == NULL) {
		return NULL;
	}
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows;
	out->cols = m->cols;
	out->data = malloc(out->rows * out->cols * sizeof(double));

	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < out->cols; ++c) {
			out->data[r * out->cols + c] = m->data[r * m->cols + m->cols - 1 - c];
		}
	}
	
	return out;
}