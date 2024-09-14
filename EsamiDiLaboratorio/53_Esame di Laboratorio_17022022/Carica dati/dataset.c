#define _CRT_SECURE_NO_WARNINGS
#include "dataset.h"

struct dataset* dataset_load(const char* filename)
{
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return NULL;
	}
	struct dataset *outDataset = malloc(sizeof(struct dataset)); //Dataset allocato nell'heap
	outDataset->data = NULL;  //data punta ad un vettore di struct row
	//Leggo una riga
	int c;
	size_t countRows = 0; //numero righe del dataset
	while (1) {
		int count = 0;  //conta il numero di byte letti
		do {   //Leggo il filename di una riga (cioè fino alla virgola)
			c = fgetc(f);
			if (c == EOF) {
				break;
			}
			++count;
		} while (c != ',');
		
		outDataset->data = realloc(outDataset->data, (countRows + 1) * sizeof(struct row));  //Aumento di uno 
		//gli elementi del vettore di struct puntato da data
		((outDataset->data) + countRows)->filename = calloc(count, 1); //Alloco spazio per la stringa C puntata da filename
		fseek(f, -count, SEEK_CUR);
		fread(((outDataset->data) + countRows)->filename, 1, count - 1, f);
		
		count = 0;  //Leggo prognosis da una riga
		do {
			c = fgetc(f);
			++count;

		} while (c != 10);
		if (count == 6) {
			((outDataset->data) + countRows)->prognosis = 'M';
		}
		else {
			((outDataset->data) + countRows)->prognosis = 'S';
		}
		c = fgetc(f);
		if (c == EOF) {
			break;
		}
		fseek(f, -1, SEEK_CUR);
		++countRows;
	}
	outDataset->nrows = countRows + 1;

	fclose(f);
	return outDataset;
}