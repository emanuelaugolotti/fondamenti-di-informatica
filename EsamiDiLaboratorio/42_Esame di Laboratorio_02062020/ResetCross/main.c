#include "matrix.h"

void mat_destroy(struct matrix* m) {
	free(m->data);
	free(m);
}

int main(void)
{
	double Adata[] = { 1.000,  2.000,  3.000,  4.000,  5.000,
					  6.000,  7.000,  8.000,  9.000, 10.000,
					  11.000, 12.000, 13.000, 14.000, 15.000 };

	struct matrix A = { 3,5,Adata };
	struct matrix* ris;
	ris = mat_reset_cross(&A, 1, 2);

	//libero la matrice
	mat_destroy(&A);
	
	return 0;
}