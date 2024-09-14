#include "matrix.h"

struct matrix* mat_reset_cross(const struct matrix* m, size_t ir, size_t ic)
{
	if (m == NULL || ir >= m->rows || ic >= m->cols) {
		return NULL;
	}
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows;
	out->cols = m->cols;
	out->data = calloc(out->rows * out->cols, sizeof(double));

	out->data[ir * out->cols + ic] = m->data[ir * m->cols + ic];
	if (ir > 0) {
		for (size_t r = 0; r <= ir - 1; ++r) {
			if (ic > 0) {
				for (size_t c = 0; c <= ic - 1; ++c) {
					out->data[r * out->cols + c] = m->data[r * m->cols + c];
				}
			}
			if (ic < out->cols) {
				for (size_t c = ic + 1; c < out->cols; ++c) {
					out->data[r * out->cols + c] = m->data[r * m->cols + c];
				}
			}
		}
	}
	if (ir < out->rows - 1) {
		for (size_t r = ir + 1; r < out->rows; ++r) {
			if (ic > 0) {
				for (size_t c = 0; c <= ic - 1; ++c) {
					out->data[r * out->cols + c] = m->data[r * m->cols + c];
				}
			}
			if (ic < out->cols) {
				for (size_t c = ic + 1; c < out->cols; ++c) {
					out->data[r * out->cols + c] = m->data[r * m->cols + c];
				}
			}
		}
	}
	return out;
}