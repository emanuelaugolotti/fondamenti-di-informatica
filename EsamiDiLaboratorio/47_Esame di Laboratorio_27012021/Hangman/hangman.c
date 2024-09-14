#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* hangman(const char* frase, const char* lettere)
{
	
	if (frase == NULL || lettere == NULL)
	{
		return NULL;
	}
	size_t len = strlen(frase);
	char* buffer = calloc(len + 1, 1);
	for (size_t i = 0; i < len; ++i) {
		int elemento = frase[i];
		if (!isalpha(elemento)) {
			buffer[i] = frase[i];
		}
		else {
			elemento = tolower(frase[i]);
			if (strchr(lettere, elemento) == NULL) {
				buffer[i] = '*';
			}
			else {
				buffer[i] = frase[i];
			}
		}
	}

	return buffer;
}