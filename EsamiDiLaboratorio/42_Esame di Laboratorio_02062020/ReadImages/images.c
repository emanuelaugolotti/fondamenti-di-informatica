#define _CRT_SECURE_NO_WARNINGS
#include "images.h"

struct image* read_images(const char* filename, size_t* n)
{
	if (filename == NULL || n == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	struct image* out = NULL;
	size_t count = 0; //conta il numero di immagini lette
	while (1) {
		char nome[255];
		size_t altezza, larghezza;
		int ris = fscanf(f, " %254[^:]:%zu:%zu", nome, &altezza, &larghezza);
		if (ris != 3) {
			if (count == 0) {
				fclose(f);
				return NULL;
			}
			break;  //fine del file
		}
		out = realloc(out, (count + 1) * sizeof(struct image));
		out[count].height = altezza;
		out[count].width = larghezza;
		strcpy(out[count].name, nome);
		++count;
	}
	*n = count;
	fclose(f);
	return out;
}