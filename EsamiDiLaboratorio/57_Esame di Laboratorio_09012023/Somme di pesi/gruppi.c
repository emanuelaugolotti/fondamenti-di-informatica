#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int* read_gruppi(const char* filename, size_t* ngruppi)
{
	if (filename == NULL || ngruppi == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL || feof(f)) {
		return NULL;
	}
	int* out = NULL;
	int count = 0;
	int somma = 0;
	while (1) {
		int letto;
		int ris = fscanf(f, "%i%*1[\n]", &letto);
		char s[2];
		ris = fscanf(f, "%1[\n]",s);
		if (ris == 1) {
			out = realloc(out, (count + 1) * sizeof(int));
			somma += letto;
			out[count] = somma;
			++count;
			somma = 0;
			continue;
		}
		else if (ris == EOF) {
			out = realloc(out, (count + 1) * sizeof(int));
			somma += letto;
			out[count] = somma;
			++count;
			break;
		}
		somma += letto;
	}
	*ngruppi = count;
	fclose(f);
	return out;
}