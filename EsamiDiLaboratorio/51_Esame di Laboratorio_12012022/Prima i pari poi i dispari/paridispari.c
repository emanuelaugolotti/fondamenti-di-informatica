#include "paridispari.h"

void paridispari(int* v, size_t n)
{
	//Se v=NULL, oppure se n=0, la funzione non fa nulla.
	if (v == NULL || n == 0) {
		return;
	}

	int* copy = calloc(n, sizeof(int));
	size_t paripos = 0, copypos = 0;
	size_t countdisp = 0;  //conta i dispari
	for (size_t i = 0; i < n; ++i) {
		if (v[i] % 2 == 0) {
			v[paripos] = v[i];
				++paripos;
		}
		else {
			copy[copypos] = v[i];
			++copypos;
			++countdisp;
		}
	}
	memcpy(v + paripos, copy, countdisp * sizeof(int));

	free(copy);
	return;
}