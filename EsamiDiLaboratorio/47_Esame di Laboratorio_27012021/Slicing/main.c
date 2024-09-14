#include <stdlib.h>

extern int* slicing(const int* v, size_t* n, size_t start, size_t end, int step);

int main(void)
{
	int vett[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int* ris;
	size_t num;
	ris = slicing(vett, &num, 2, 6, -3);

	free(ris);
	
	return 0;
}