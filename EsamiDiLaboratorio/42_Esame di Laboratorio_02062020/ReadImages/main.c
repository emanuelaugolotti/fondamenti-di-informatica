#include "images.h"

int main(void)
{
	size_t numero_immagini;
	struct image* ris;
	ris = read_images("file1.txt", &numero_immagini);

	//libero la memoria
	free(ris);
	return 0;
}