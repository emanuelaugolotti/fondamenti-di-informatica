#include "matrix.h"

int main(void)
{
	double Adata[] = { 1,2,3,4,5,6 };
	struct matrix A = { 2,3,Adata };
	struct matrix* ris;
	ris = mat_normalize_rows(&A);
	
	
	return 0;
}