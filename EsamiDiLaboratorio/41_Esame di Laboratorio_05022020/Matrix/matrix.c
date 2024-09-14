#include "matrix.h"

struct matrix* mat_replicate(const struct matrix* m)
{
	if (m == NULL) {
		return NULL;
	}

	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows;
	out->cols = 2 * m->cols;
	out->data = calloc(out->cols * out->rows, sizeof(double));

	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < (out->cols) / 2; ++c) {
			out->data[r * out->cols + c] = m->data[r * m->cols + c];
		}
		for (size_t c = (out->cols) / 2 ; c < out->cols; ++c) {
			out->data[r * out->cols + c] = m->data[r * m->cols + c - m->cols];
		}
	}
	
	return out;
}