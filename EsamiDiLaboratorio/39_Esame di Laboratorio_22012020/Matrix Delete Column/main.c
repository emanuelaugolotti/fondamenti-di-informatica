#include"matrix.h"

void mat_destroy(struct matrix* m)
{
	if (m != NULL) {
		free(m->data);
		free(m);
	}
}

void printMatrix(struct matrix* m)
{
	if (m != NULL) {
		for (size_t r = 0; r < m->rows; ++r) {
			for (size_t c = 0; c < m->cols; ++c) {
				printf("%6.1f", m->data[r * m->cols + c]);
			}
			printf("\n");
		}
	}
}

int main(void)
{
	double Adata[] = { 1, 2, 3, 4, 5,
					   6, 7, 8, 9, 10,
		               11,12,13,14,15,
		               16,17,18,19,20 };

	struct matrix A = { 4, 5, Adata };
	struct matrix* ris;
	ris = mat_delete_col(&A, 1);

	printMatrix(ris);
	
	//libero la memoria
	mat_destroy(ris);
	
	return 0;
}