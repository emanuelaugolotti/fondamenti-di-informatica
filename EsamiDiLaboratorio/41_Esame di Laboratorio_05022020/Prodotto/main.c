#include <stdlib.h>

extern int prodotto_altri_due(const int* v, size_t n);

int main(void)
{
	int v[] = { 10, 2, 8, 4, 1, 1, 6, 8, 3, 7, 3, 9, 7, 4, 8, 5, 1, 3, 5, 3, 8, 4, 8, 9, 4, 2, 6, 3, 7, 10 };
	int ris;
	ris = prodotto_altri_due(v, 30);
	
	return 0;
}