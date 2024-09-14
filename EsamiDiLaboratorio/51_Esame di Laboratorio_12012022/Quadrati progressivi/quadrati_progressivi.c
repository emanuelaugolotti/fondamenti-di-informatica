#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void quadrati_progressivi(FILE* f, int n)
{
	if (n <= 0) {  //Qualora la funzione riceva un valore di n non positivo, non scrive niente sul file.
		return;
	}
	int start, stampa;
	for (int r = 1; r < n; ++r) {  //stampo n - 1 righe
	//scorro tutti gli elementi di una riga
		for (int pos = 1; pos <= n; ++pos) {
			if (pos <= r) {
				stampa = r % 10;
				fprintf(f, "%i ", stampa);
				start = r % 10 + 1;
			}
			else {
				stampa = start % 10;
				fprintf(f, "%i ", stampa);
				++start;
				if (start > 9) {
					start %= 10;
				}
			}
			
		}
		fprintf(f, "\n");
	}
	//stampo l'ultima riga
	stampa = n % 10;
	for (int i = 0; i < n - 1; ++i) {
		fprintf(f, "%i ", stampa);
	}
	fprintf(f, "%i", stampa);
	return;
}