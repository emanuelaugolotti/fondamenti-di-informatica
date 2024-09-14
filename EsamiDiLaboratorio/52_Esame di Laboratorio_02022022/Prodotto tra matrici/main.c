#include "matrix.h"

void mat_destroy(struct matrix* mat) {
	if (mat != NULL) {
		free(mat->data);
		free(mat);
	}
}

int main(void)
{
	struct matrix A;
	A.rows = 3;
	A.cols = 5;
	double Xdata[] = { 1.000,  2.000,  3.000,  4.000,  5.000,
 6.000,  7.000,  8.000,  9.000, 10.000,
11.000, 12.000, 13.000, 14.000, 15.000 };
	A.data = Xdata;
	
	double Bdata[] = { -0.900,  0.800, - 2.900,  0.600,  3.000, - 0.100, - 2.900,
- 0.900,  3.200, - 1.100,  1.800, - 2.000, - 1.700, - 0.200,
- 0.300,  2.200,  3.900, - 4.200,  2.800, - 1.300, - 0.400,
 1.400, - 4.300,  3.600,  4.400,  0.100, - 3.200,  4.600,
 0.600,  5.000,  1.900, - 0.100, - 0.100,  3.700, - 3.200 };
	struct matrix B = { 5, 7, Bdata };

	struct matrix *C = mat_mul(&A, &B);
	mat_destroy(C);
	return 0;
}