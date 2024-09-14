#include "matrix.h"
 
void mat_destroy(struct matrix* m)
{
	if (m != NULL) {
		free(m->data);
		free(m);
	}
	return;
}

void mat_print(struct matrix* m)
{
	for (size_t r = 0; r < m->rows; ++r) {
		for (size_t c = 0; c < m->cols; ++c) {
			printf("%-6.2f", m->data[r * m->cols + c]);
		}
		printf("\n");
	}
	return;
}


int main(void)
{
	double Adata[] = { 1.000,  2.000,  3.000,  4.000,  5.000,  6.000,  7.000,  8.000,  9.000, 10.000,
11.000, 12.000, 13.000, 14.000, 15.000, 16.000, 17.000, 18.000, 19.000, 20.000 };
	
	struct matrix A = { 2, 10, Adata };
	struct matrix* ris = mirror_mat(&A);
	mat_print(ris);
	mat_destroy(ris);

	return 0;
}