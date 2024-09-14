#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include<stdlib.h>

char* codifica_morse(const char* testo)
{
	if (testo == NULL)
	{
		return NULL;
	}
	const char *morse[] = { "._","_...","_._.","_..",".",".._.", "__.", "....","..",".___","_._",
							"._..","__","_.","___",".__.","__._","._.",
							"...","_",".._","..._",".__","_.._","_.__","__.." };
	size_t len = strlen(testo);
	size_t count = 0;  //conta gli spazi in testo
	for (size_t i = 0; i < len; ++i) {
		if (testo[i] == ' ') {
			++count;
		}
    }
	char* out = calloc((len - count) * 4 + (len - count - 1) + count + 1, 1);
	for (size_t i = 0; i < len; ++i) {
		if (testo[i] == ' ') {
			strcat(out, "/ ");
		}
		else {
			size_t pos = testo[i] - 'A';
			strcat(out, morse[pos]);
			if (i != len - 1) {
				strcat(out, " ");
			}
		}
	}
	out = realloc(out, (1 + strlen(out)));
	return out;
}