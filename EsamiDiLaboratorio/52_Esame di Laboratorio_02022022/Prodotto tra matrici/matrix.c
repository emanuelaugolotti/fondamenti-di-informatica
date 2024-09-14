#include "matrix.h"

struct matrix* mat_mul(const struct matrix* m1, const struct matrix* m2)
{
	if (m1 == NULL || m2 == NULL || m1->cols != m2->rows) {
		return NULL;
	}

	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m1->rows;
	out->cols = m2->cols;
	out->data = malloc((out->rows * out->cols) * sizeof(double));

	//riempio la matrice
	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < out->cols; ++c) {
			double elemento = 0;
			size_t stop = m1->cols;
			for (size_t i = 0; i < stop; ++i) {
				elemento += m1->data[r * m1->cols + i] * m2->data[i * m2->cols + c];
			}
			out->data[r * out->cols + c] = elemento;
		}
	}
	
	return out;
}