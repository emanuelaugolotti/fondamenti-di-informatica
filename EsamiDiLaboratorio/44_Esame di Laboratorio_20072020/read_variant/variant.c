#include "variant.h"

void* read_variant(FILE* f, char* type)
{
	if (f == NULL || type == NULL || feof(f)) {
		return NULL;
	}
	void* out = NULL;
	char letto;
	size_t ris = fread(&letto, 1, 1, f);
	*type = letto;
	switch (*type) {
	case 'c': {
		out = realloc(out, 1);
		ris = fread(out, 1, 1, f);
		break;
	}
	case 's': {
		out = realloc(out, sizeof(short));
		ris = fread(out, sizeof(short), 1, f);
		break;
	}
	case 'i': { 
		out = realloc(out, sizeof(int));
		ris = fread(out, sizeof(int), 1, f);
		break;
	}
	case 'l': {
		out = realloc(out, sizeof(long long));
		ris = fread(out, sizeof(long long), 1, f);
		break;
	}
	case 'f': {
		out = realloc(out, sizeof(float));
		ris = fread(out, sizeof(float), 1, f);
		break;
	}
	case 'd': {
		out = realloc(out, sizeof(double));
		ris = fread(out, sizeof(double), 1, f);
		break;
	}
		default: return NULL;
	}
	if (ris != 1) {
		return NULL;
	}
	return out;
}