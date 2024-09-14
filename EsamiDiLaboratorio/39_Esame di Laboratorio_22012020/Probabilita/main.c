#include <stdlib.h>
#include <stdint.h>

extern double* probabilita(const uint32_t* v, size_t n);

int main(void)
{
	uint32_t v[5] = { 1, 2, 3, 4, 5 };
	double* ris;
	ris = probabilita(v, 5);
	free(ris);
	return 0;
}