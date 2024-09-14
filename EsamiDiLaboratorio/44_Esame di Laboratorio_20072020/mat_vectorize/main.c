#include "matrix.h"

int main(void)
{
	double Adata[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
	struct matrix A = { 3, 3, Adata };
	struct vector* ris = mat_vectorize(&A, BY_COLUMN);

	//libero la memoria
	if (ris != NULL) {
		free(ris->data);
		free(ris);
	}
	return 0;
}