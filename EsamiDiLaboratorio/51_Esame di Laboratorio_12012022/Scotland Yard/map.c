#define _CRT_SECURE_NO_WARNINGS
#include "map.h"

struct connections* load_connections(const char* filename)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	struct connections* connessioni = malloc(sizeof(struct connections));
	size_t numNodi;
	int ris = fscanf(f, "%zu\n", &numNodi);  //leggo il numero di nodi
	if (ris != 1) {
		return NULL;
	}
	connessioni->n = numNodi;
	connessioni->data = calloc(numNodi * numNodi, sizeof(bool));
	
	for (size_t countriga = 0; countriga < numNodi; ++countriga) {
		while (true) {
			size_t letto, pos, simmetrico;
			ris = fscanf(f, "%zu ", &letto);
			if (ris != 1) {
				if (fgetc(f) == '.') {
					break;  //la riga è finita
				}
				else {
					free(connessioni->data);
					free(connessioni);
				}
			}
			pos = countriga * numNodi + letto - 1;
			simmetrico = (letto - 1) * numNodi + countriga;
			connessioni->data[pos] = true;
			connessioni->data[simmetrico] = true;
		}
	}

	fclose(f);
	return connessioni;
}