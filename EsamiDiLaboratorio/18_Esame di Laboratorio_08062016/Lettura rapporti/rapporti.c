#define _CRT_SECURE_NO_WARNINGS
#include "rapporti.h"

struct rapporto* leggi_rapporti(const char* filename, uint16_t* n) 
{
	if (filename == NULL || n == NULL) {
		return NULL;
	}
	
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return NULL;  //non è riuscita ad aprire il file
	}

	//leggo il numero di rapporti presenti nel file che è un intero senza segno a 16 bit
	size_t ris = fread(n, sizeof(uint16_t), 1, f);
	if (ris != 1) {
		return NULL;  //file vuoto
	}
	struct rapporto* letti = malloc((*n) * sizeof(struct rapporto));
	
	for (uint16_t i = 0; i < *n; ++i) {
		//leggo il campo id (intero senza segno a 16 bit codificato in little endian)
		fread(&(letti[i].id), sizeof(uint16_t), 1, f);
		//leggo il campo tipo (carattere alfabetico)
		fread(&(letti[i].tipo), 1, 1, f);
		//leggo un valore (numero in virgola mobile a 32 bit codificato in little endian)
		fread(&(letti[i].valore), sizeof(float), 1, f);
	}
	
	fclose(f);
	return letti;
}