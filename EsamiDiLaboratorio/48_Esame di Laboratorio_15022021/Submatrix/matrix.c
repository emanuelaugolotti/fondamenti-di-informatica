#include "matrix.h"

struct matrix* mat_submatrix(const struct matrix* mat, const int* row_idxs, const int* col_idxs)
{
	if (mat == NULL || row_idxs == NULL || col_idxs == NULL) {
		return NULL;
	}
	size_t count = 0;
	for (int i = 0; row_idxs[i] >= 0; ++i) {
		if ((size_t)(row_idxs[i]) > mat->rows - 1) {
			count = 0;
			break;
		}
		++count;
	}
	size_t nrows = count;
	count = 0;
	for (size_t i = 0; col_idxs[i] >= 0; ++i) {
		if ((size_t)(col_idxs[i]) > mat->cols - 1) {
			count = 0;
			break;
		}
		++count;
	}
	size_t ncols = count;
	if (nrows == 0 || ncols == 0) {
		return NULL;
	}
	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = nrows;
	out->cols = ncols;
	out->data = malloc(out->rows * out->cols * sizeof(double));
	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < out->cols; ++c) {
			out->data[r * out->cols + c] = mat->data[row_idxs[r] * mat->cols + col_idxs[c]];
		}
	}
	return out;
}