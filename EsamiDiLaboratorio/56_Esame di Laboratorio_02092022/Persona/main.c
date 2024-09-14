#include "persona.h"

int main(void)
{
	struct persona* ris;
	size_t nlette;
	ris = leggi_persone("file3.txt", &nlette);
	
	if (ris != NULL) {
		free(ris);
	}
	
	return 0;
}