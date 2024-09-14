#include "matrix.h"

struct matrix* matrix_quadruplica(const struct matrix* m)
{
	if (m == NULL) {
		return NULL;
	}

	//nuova struct matrix allocata dinamicamente sull'heap
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m->rows * 2;
	out->cols = m->cols * 2;
	out->data = malloc(out->rows * out->cols * sizeof(double));

	//riempio la matrice
	size_t rout = 0, rm = rout;
	size_t condizione = m->rows;
	for (size_t i = 0; i < 2; ++i) {
		//copio i due angoli superiori della matrice: destro e sinistro
			for (size_t r = rout; r < condizione; ++r) {
				for (size_t c = 0; c < m->cols; ++c) { //ciclo for per copiare l'angolo dx
					out->data[r * out->cols + c] = m->data[rm * m->cols + c];
				}
				for (size_t c = m->cols; c < (m->cols * 2); ++c) { //ciclo for per copiare l'angolo sn
					out->data[r * out->cols + c] = m->data[rm * m->cols + c - m->cols];
				}
				++rm;
			}
		//adesso devo copiare i due angoli inferiori della matrice: destro e sinistro
		rout = m->rows;
		condizione = out->rows;
		rm = rout - m->rows;
	}

	return out;
}