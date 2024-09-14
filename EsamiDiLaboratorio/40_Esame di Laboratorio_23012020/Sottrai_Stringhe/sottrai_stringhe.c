#include <stdlib.h>
#include <string.h>

char* sottrai_stringhe(const char* a, const char* b)
{
	if (a == NULL || b == NULL) {
		return NULL;
	}
	char* endptr;
	char* out = NULL;
	unsigned long long val1 = strtoull(a, &endptr, 10);
	unsigned long long val2 = strtoull(b, &endptr, 10);
	unsigned long long differenza = val1 - val2;
	if (differenza == 0) {  //Se a e b rappresentano lo stesso numero, la funzione restituisce "0"
		out = realloc(out, 2);
		out[0] = '0';
		out[1] = 0;
		return out;
	}
	unsigned char cifra, count = 0;
	while (differenza != 0) {
		cifra = differenza % 10;
		differenza = differenza / 10;
		out = realloc(out, count + 1);
		out[count] = cifra;
		++count;
	}
	out = realloc(out, count + 1);
	out[count] = 0; //terminatore
	char* new = calloc(count + 1, 1);
	for (unsigned long long i = 0; i < count; ++i) {
		new[i] = '0' + out[count - 1 - i];
	}
	free(out);
	return new;
}