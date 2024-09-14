#include "matrix.h"

struct matrix* mat_delete_col(const struct matrix* m, size_t i)
{
	//Se i specifica una colonna non valida, se m ha una sola colonna, o se m è NULL, la funzione restituisce NULL.
	if (m == NULL || m->cols == 1 || i >= m->cols) {
		return NULL;
	}
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows;
	out->cols = m->cols - 1;
	out->data = malloc(out->rows * out->cols * sizeof(double));

	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < i; ++c) {
			out->data[r * out->cols + c] = m->data[r * m->cols + c];
		}
		for (size_t c = i; c < out->cols; ++c) {
			out->data[r * out->cols + c] = m->data[r * m->cols + c + 1];
		}
	}
	return out;
}