#include <stdlib.h>

extern int* convolution3(const int* v, size_t lenv, const int k[3])
{
	if (v == NULL || k == NULL || lenv == 0) {
		return NULL;
	}
	int* out_vector = malloc(lenv * sizeof(int));

	//Riempio il vettore
	out_vector[0] = v[1] * k[0] + v[0] * k[1];
	out_vector[lenv - 1] = v[lenv - 1] * k[1] + v[lenv - 2] * k[2];
	for (size_t n = 1; n < lenv - 1; ++n) {
		out_vector[n] = 0;
		for (size_t m = 0; m < 3; ++m) {
			size_t posizione = n + 1 - m;
				out_vector[n] += v[posizione] * k[m];
		}
	}
	return out_vector;
}