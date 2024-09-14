#define _CRT_SECURE_NO_WARNINGS
#include "read_dvec.h"

double converti(int val)
{
	if (val >= exp2(15)) {
		int tmp = val - exp2(16);
		val = tmp;
	}
	double ris = val / exp2(14);
	return ris;
}

struct dvec* read_dvec_comp(const char* filename)
{
	struct dvec* out = malloc(sizeof(struct dvec));
	out->n = 0;
	out->d = NULL;
	if (filename == NULL) {
		return out;
	}
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return out;
	}
	size_t count = 0;  //conta il numero di valori presenri nel file
	while (1) {
		int c = fgetc(f);
		if (c == EOF) {
			if (count == 0) {
				fclose(f);
				return out;  //il file non contiene alcun valore
			}
			break;  //Il file è finito
		}
		int byte1 = c;
		c = fgetc(f);
		int byte2 = (c % 256) << 8;
		out->d = realloc(out->d, (count + 1) * sizeof(double));
		out->d[count] = converti(byte1 + byte2);
		++count;
	}
	out->n = count;
	fclose(f);
	return out;
}