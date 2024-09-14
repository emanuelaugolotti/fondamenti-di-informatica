#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

char *converti(const char* dacercare, const char** cod)
{
	char* letteraConv = calloc(2, 1);
	for (size_t i = 0; i < 26; ++i) {
		int p = strcmp(cod[i], dacercare);
		if (p == 0) {  //l'ho trovata
			letteraConv[0] = (char)i + 'A';
			return letteraConv;
		}
	}
	free(letteraConv);
	return NULL;
}

char* decodifica_morse(const char* codice)
{
	if (codice == NULL) {
		return NULL;
	}
	const char* codifica[] = { "._", "_...", "_._.",  "_..", ".", ".._.", "__.",  "....","..",".___","_._",
	"._..","__","_.","___", ".__.", "__._", "._.","...","_",".._", "..._", ".__", "_.._", "_.__", "__.." };
	size_t size = 1;
	char* out = calloc(size, 1);
	char* lettera = NULL;
	char tmp[5] = { 0 };
	for (size_t i = 0; i < strlen(codice); ++i) {
		if (codice[i] == ' ') {
			continue;
		}
		else if (codice[i] == '/') {
			out = realloc(out, size + 1);
			++size;
			strcat(out, " ");
		}
		else {
			size_t count = 0;
			while (codice[i] != ' ' && i < strlen (codice)) {
				tmp[count] = codice[i];
				++count;
				++i;
			}
			lettera = converti(tmp, codifica);
			out = realloc(out, size + 1);
			++size;
			strcat(out, lettera);
			memset(tmp, 0, 5);
			free(lettera);
		}
	}
	return out;
}