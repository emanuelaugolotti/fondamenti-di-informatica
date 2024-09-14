#include "matrix.h"

//Funzione che distrugge la struct matrice e i dati puntati da data
void mat_destroy(const struct matrix *mat) {
	if (!mat) {
		free(mat->data);
		free(mat);
	}
}

int main(void)
{
	struct matrix A;
	A.rows = 2;
	A.cols = 3;
	double Adata[] = { 1.0, 2.0, 3.0, 
					   4.0, 5.0, 6.0 };
	A.data =Adata;
	struct matrix* matRis = mat_scale(&A, 7.0);
	mat_destroy(matRis);

	double Bdata[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
	struct matrix B = { 3, 3, Bdata };
	matRis = mat_scale(&B, 7.0);
	mat_destroy(matRis);
	
	return 0;
}