#include "matrix.h"

extern struct matrix* mat_pad(const struct matrix* mat)
{
	//Il puntatore alla matrice mat non sarà mai NULL.
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = (mat->rows - 1) + mat->rows;
	out->cols = (mat->cols - 1) + mat->cols;
	out->data = calloc(out->rows * out->cols, sizeof(double));

	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < out->cols; ++c) {
			if (r % 2 == 0 && c % 2 == 0) {
				out->data[r * out->cols + c] = mat->data[(r / 2) * mat->cols + c / 2];
			}
		}
	}
	
	return out;
}
