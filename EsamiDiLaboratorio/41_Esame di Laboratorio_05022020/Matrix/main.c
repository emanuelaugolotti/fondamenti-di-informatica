#include "matrix.h"

void mat_destroy(struct matrix* m)
{
	if (m != NULL) {
		free(m->data);
		free(m);
	}
	return;
}


int main(void)
{
	double Adata[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
	struct matrix A = { 3, 3, Adata };
	struct matrix* ris;
	
	ris = mat_replicate(&A);

	mat_destroy(ris);
	
	return 0;
}