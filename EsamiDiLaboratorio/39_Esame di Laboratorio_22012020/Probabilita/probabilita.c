#include <stdlib.h>
#include <stdint.h>
#include <string.h>

double sommatoria(const uint32_t *vett, size_t num)
{
	double somma = 0;
	for (uint32_t i = 0; i < num; ++i) {
		somma += vett[i];
	}
	return somma;
}

double* probabilita(const uint32_t* v, size_t n)
{
	if (v == NULL || n == 0) {
		return NULL;
	}
	uint32_t* vect = calloc(n, sizeof(uint32_t));
	if (memcmp(v, vect, n) == 0) {
		free(vect);
		return NULL;
	}
	double* out = malloc(n * sizeof(double));
	for (uint32_t i = 0; i < n; ++i) {
		out[i] = v[i] / sommatoria(v, n);
	}
	free(vect);
	return out;
}