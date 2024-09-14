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
	
	size_t count = 0 ; //conta i numeri a 16 bit in complemento a 2 in little endian letti dal file binario
	while (1) {
		short letto;
		size_t ris = fread(&letto, 2, 1, f);
		if (ris != 1) {
			break;
		}
		out->d = realloc(out->d, (count + 1) * sizeof(double));
		out->d[count] = letto / exp2(14);
		++count;
	}
	out->n = count;
	
	fclose(f);  //chiudo il file
	return out;
}