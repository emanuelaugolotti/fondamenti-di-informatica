#include "matrix.h"

void mat_destroy(const struct matrix* mat)
{
	if (mat) {
		free(mat->data);
		free(mat);
	}
	return;
}

int main(void)
{
	double Adata[] = {1.0, 2.0, 3.0, 
		              4.0, 5.0, 6.0};
	struct matrix A = { 2, 3, Adata };

	double Bdata[] = { 7.0,
					   8.0};
	struct matrix B = { 2, 1, Bdata };
	
	struct matrix *C = mat_rowmul(&A, &B);

	mat_destroy(C);
	return 0;
}