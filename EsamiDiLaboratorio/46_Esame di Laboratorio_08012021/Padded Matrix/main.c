#include "matrix.h"

void mat_destroy(struct matrix* m) {
	if (m != NULL) {
		free(m->data);
		free(m);
	}
}

int main(void)
{
	double Adata[] = { 1,2,3,4,5,6,7,8,9 };
	struct matrix A = { 9,1,Adata };
	struct matrix* ris;
	ris = mat_pad(&A);

	//libero la memoria
	mat_destroy(&A);

	return 0;
}