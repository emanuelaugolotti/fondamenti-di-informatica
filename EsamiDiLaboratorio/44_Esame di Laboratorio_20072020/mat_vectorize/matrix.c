#include "matrix.h"

struct vector* mat_vectorize(const struct matrix* m, enum vectorize_by dir)
{
	if (m == NULL) {
		return NULL;
	}
	struct vector* out = malloc(sizeof(struct vector));
	out->data = malloc(m->rows * m->cols * sizeof(double));
	out->n = m->rows * m->cols;
	switch (dir) {
	case BY_ROW: {
		size_t i = 0;
		for (size_t r = 0; r < m->rows; ++r) {
			for (size_t c = 0; c < m->cols; ++c) {
				out->data[i] = m->data[r * m->cols + c];
				++i;
			}
		}
		break;
	}
	case BY_COLUMN: {
		size_t i = 0;
		for (size_t c = 0; c < m->cols; ++c) {
			for (size_t r = 0; r < m->rows; ++r) {
				out->data[i] = m->data[r * m->cols + c];
				++i;
			}
		}
		break;
	}
	default: return NULL;
	}
	return out;
}