#include "matrix.h"

bool scalar_mult(struct matrix* dst, const struct matrix* src, double k, bool accumulate)
{
	if (dst == NULL || src == NULL || dst->rows != src->rows || dst->cols != src->cols) {
		return false;
	}
	switch (accumulate) {
	case false: {
		for (size_t r = 0; r < dst->rows; ++r) {
			for (size_t c = 0; c < dst->cols; ++c) {
				dst->data[r * dst->cols + c] = k * src->data[r * src->cols + c];
			}
		}
		break;
	}
	case true: {
		for (size_t r = 0; r < dst->rows; ++r) {
			for (size_t c = 0; c < dst->cols; ++c) {
				dst->data[r * dst->cols + c] = k * src->data[r * src->cols + c] + dst->data[r * dst->cols + c];
			}
		}
		break;
	}
	}
	return true;
}