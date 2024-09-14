#include "matrix.h"

void mat_destroy(struct matrix* m)
{
	if (m != NULL) {
		free(m->data);
		free(m);
	}
}

void mat_print(struct matrix* m)
{
	for (size_t r = 0; r < m->rows; ++r) {
		for (size_t c = 0; c < m->cols; ++c) {
			printf("%7.1f", m->data[r * m->cols + c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int row_idxs[] = { 1, 4, -1 };
	int col_idxs[] = { 0, 2, 3, -1 };
	double Adata[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	struct matrix A = { 3,4,Adata };
	struct matrix* ris;
	ris = mat_submatrix(&A, row_idxs, col_idxs);

	mat_print(ris);
	mat_destroy(ris);
	
	return 0;
}