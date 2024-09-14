#define _CRT_SECURE_NO_WARNINGS
#include "read_dvec.h"

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
	size_t count = 0;  //conta il numero di valori presenti nel file
	while (1) {
		short val_letto;
		//leggo dal file binario numeri a 16 bit in complemento a 2 in little endian
		size_t ris = fread(&val_letto, 1, 2, f);
		if (ris != 2) {
			break; 
		}
		out->d = realloc(out->d, (count + 1) * sizeof(double));
		out->d[count] = val_letto / exp2(14);
		++count;
	}
	out->n = count;
	fclose(f);
	return out;
}