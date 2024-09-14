#include "matrix.h"

int main(void)
{
	double Adata[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	struct matrix A = { 3, 3, Adata };

	double* ris;
	ris = matrix_snake(&A);
	free(ris);
	
	return 0;
}