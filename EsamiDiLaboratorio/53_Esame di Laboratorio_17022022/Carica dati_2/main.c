#include "dataset.h"

void dataset_destroy(struct dataset* dts)
{
	if (dts != NULL) {
		for (size_t i = 0; i < dts->nrows; ++i) {
			free(dts->data[i].filename);  //Libero la memoria puntata da filename di ogni riga
		}
		free(dts->data);  //Libero il vettore di struct row puntato da data
		free(dts);  //Libero la struttura dataset
		return;
	}
	return;
}

int main(void)
{
	struct dataset* p;
	p = dataset_load("file1.txt");

	p = dataset_load("file2.txt");

	p = dataset_load("file3.txt");

	//Libero la memoria del dataset
	dataset_destroy(p);

	return 0;
}