#include "map.h"

int main(void)
{
	struct connections* ris;
	ris = load_connections("full.txt");
	
	//stampo la matrice
	for (int i = 0; i < ris->n; ++i) {
		for (int c = 0; c < ris->n; ++c) {
			printf("%u", ris->data[i * ris->n + c]);
		}
		printf("\n");
	}

	free(ris->data);
	free(ris);
	return 0;
}