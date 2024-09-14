#define _CRT_SECURE_NO_WARNINGS
#include "demography.h"

struct city* read_cities(const char* filename, uint32_t* n)
{
	if (filename == NULL || n == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return NULL;
	}
	uint32_t count;
	struct city* out = NULL;
	size_t ris = fread(&count, sizeof(uint32_t), 1, f);
	*n = count;
	if (ris != 1) {
		fclose(f);
		return NULL;
	}
	out = malloc(count * sizeof(struct city));
	for (uint32_t i = 0; i < count; ++i) {
		out[i].name = calloc(255, sizeof(char));;
		size_t conta = 0;
		while (1) {
			int c = fgetc(f);
			if (c == 0) {
				break;
			}
			out[i].name[conta] = c;
			++conta;
		}
		uint32_t letto;
		fread(&letto, sizeof(uint32_t), 1, f);
		out[i].population = letto;
	}
	fclose(f);
	return out;
}