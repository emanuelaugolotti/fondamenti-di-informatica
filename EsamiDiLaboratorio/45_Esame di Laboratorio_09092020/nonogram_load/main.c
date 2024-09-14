#include "nonogram.h"

void print_img(struct nonogram* img)
{
	if (img != NULL) {
		for (size_t r = 0; r < img->n; ++r) {
			for (size_t c = 0; c < img->n; ++c) {
				printf("%c", img->schema[r * img->n + c]);
			}
			printf("\n");
		}
	}
}

int main(void)
{
	struct nonogram* immagine = malloc(sizeof(struct nonogram));
	bool ris;
	ris = nonogram_load(immagine, "nonogram2.txt");
	print_img(immagine);
	
	free(immagine->schema);
	free(immagine);
	
	return 0;
}