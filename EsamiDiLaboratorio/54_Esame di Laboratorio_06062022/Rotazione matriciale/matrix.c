#include "matrix.h"

struct matrix* mat_rotate180(const struct matrix* m)
{
	if (m == NULL) {
		return NULL;
	}
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows;
	out->cols = m->cols;
	out->data = malloc(m->rows * m->cols * sizeof(double));

	//Riempio la matrice
	//la prima riga, letta da sinistra a destra, diventa l'ultima, scritta da destra a sinistra, 
	//la seconda diventa la penultima, e così via.
	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < out->cols; ++c) {
			Elemento(out, r, c) = Elemento(m, m->rows - r - 1, m->cols - c - 1);
		}
	}
	return out;
}