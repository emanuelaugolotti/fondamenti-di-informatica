#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern void stampa_croce(FILE* f, size_t dim);

int main(void)
{
	FILE* f = fopen("prova.txt", "w");
	
	if (f == NULL) {
		return NULL;
	}
	
	stampa_croce(f, 0);
	stampa_croce(f, 1);
	stampa_croce(f, 2);
	stampa_croce(f, 9);

	fclose(f);
	return;
}