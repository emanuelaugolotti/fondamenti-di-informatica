#include "matrix.h"

void matrixPrint(struct matrix* m)
{
	for (size_t r = 0; r < m->rows; ++r) {
		for (size_t c = 0; c < m->cols; ++c) {
			printf("%6.1f", m->data[r * m->cols + c]);
		}
		printf("\n");
	}
}

int main(void)
{
	double Sdata[] = { 9,8,7,6,5,4,3,2,1 };
	struct matrix sorgente = { 3,3,Sdata };
	double Ddata[] = { 1,2,3,4,5,6,7,8,9 };
	struct matrix destinazione = { 3,3,Ddata };
	bool ris;
	ris = scalar_mult(&destinazione, &sorgente, 2, true);
	matrixPrint(&destinazione);

	return 0;
}