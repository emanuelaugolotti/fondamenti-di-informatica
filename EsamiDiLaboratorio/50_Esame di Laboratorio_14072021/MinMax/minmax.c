#include <stdlib.h>

void minmax(const int* v, size_t n, int* min, int* max)
{
	//Se n=0 o v=NULL la funzione non modifica le variabili puntate da min e max
	if (n == 0 || v == NULL) {
		return;
	}

	int massimo = v[0];
	int minimo = v[0];
	for (size_t i = 0; i < n; ++i) { //scorro tutti gli elementi del vettore v
		if (v[i] < minimo) {
			minimo = v[i];
		}
		if (v[i] > massimo) {
			massimo = v[i];
		}
	}
	*min = minimo;
	*max = massimo;

	return;
}