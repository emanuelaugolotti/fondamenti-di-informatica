#include "matrix.h"

struct matrix* mat_scale(const struct matrix *m, double x)
{
	if (m == NULL) {  //puntatore passato alla funzione è NULL
		return NULL;
	}
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows;
	out->cols = m->cols;
	out->data = calloc(m->cols * m->rows, sizeof(double));

	for (size_t r = 0; r < out->rows; ++r) {  //Scorro le righe
		for (size_t c = 0; c < out->cols; ++c) {  //Per ogi riga scorro tutte le colonne
			Elemento(out, r, c) = Elemento(m, r, c) * x;
		}
	}
	return out;
}