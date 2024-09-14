#include "matrix.h"

struct matrix* mat_rendiquadrata(const struct matrix* a)
{
	struct matrix* quadrata = malloc(sizeof(struct matrix));
	quadrata->rows = a->rows > a->cols ? a->rows : a->cols;
	quadrata->cols = quadrata->rows;
	quadrata->data = calloc(quadrata->rows * quadrata->cols, sizeof(double));

	for (size_t r = 0; r < a->rows; ++r) {
		for (size_t c = 0; c < a->cols; ++c) {
			quadrata->data[r * quadrata->cols + c] = a->data[r * a->cols + c];
		}
	}
	
	return quadrata;
}