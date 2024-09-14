#include "matrix.h"

struct matrix* mat_rowmul(const struct matrix* m1, const struct matrix* m2)
{
	if (m1 == NULL || m2 == NULL) {
		return NULL;
	}
	if (m2->rows != m1->rows || m2->cols != 1) {  //moltiplicazione per righe non è applicabile
		return NULL;
	}
	struct matrix *out = malloc(sizeof(struct matrix));
	out->rows = m1->rows;
	out->cols = m1->cols;
	out->data = malloc(out->rows * out->cols * sizeof(double));

	//Riempio la matrice
	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < out->cols; ++c) {
			Elemento(out, r, c) = Elemento(m1, r, c) * Elemento(m2, r, 0);
		}
	}
	
	return out;
}