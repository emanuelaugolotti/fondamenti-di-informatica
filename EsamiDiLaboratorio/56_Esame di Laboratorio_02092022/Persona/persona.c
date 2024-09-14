#define _CRT_SECURE_NO_WARNINGS
#include "persona.h"

struct persona* leggi_persone(const char* filename, size_t* size)
{
	*size = 0;
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	
	size_t count;
	int ris = fscanf(f, "%zu\n", &count);
	if (ris != 1) {
		fclose(f);
		return NULL;  //file vuoto
	}

	struct persona* personeLette = NULL;
	for (size_t i = 0; i < count; ++i)
	{
		personeLette = realloc(personeLette, (i + 1) * sizeof(struct persona));
		ris = fscanf(f, "%i , %[^\n]", &(personeLette[i].anni),&(personeLette[i].nome[0]));
		if (ris != 2) {
			break;
		}
		*size = i + 1;
	}
	if (*size != count) {
		//nel file ci sono meno persone di quelle indicate dal primo numero intero
		free(personeLette);
		*size = 0;
		fclose(f);
		return NULL;
	}

	fclose(f);
	return personeLette;
}