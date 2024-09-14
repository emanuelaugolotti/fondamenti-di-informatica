#include "dataset.h"

void dataset_destroy(struct dataset *dts)
{
	if (dts != NULL) {
		for (size_t i = 0; i < dts->nrows; ++i) {
			free((dts->data + i)->filename);  //((dts->data)+i) è il puntatore all'i-esima row
			}
		free(dts->data);
		free(dts);
		return;
	}
	return;
}

int main(void)
{
	struct dataset* ris;
	ris = dataset_load("file1.txt");

	ris = dataset_load("file2.txt");

	ris = dataset_load("file3.txt");
	
	//Libero la memoria del dataset
	dataset_destroy(ris);
	
	return 0;
}