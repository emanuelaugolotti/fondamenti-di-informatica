#include <stdlib.h>
#include <string.h>

char* somma_stringhe(const char* a, const char* b)
{
	if (a == NULL || b == NULL) {
		return NULL;
	}
	char* tmp = NULL;
	if (strtol(a, NULL, 10) == 0 && strtol(b, NULL, 10)) {
		tmp = calloc(2, 1);
		return tmp;
	}
	size_t alen = strlen(a);
	size_t blen = strlen(b);
	size_t max;
	max = alen > blen ? alen : blen;
	size_t count = 0;
	char riporto = 0, somma;
	for (size_t i = 0; i < max; ++i) {
		tmp = realloc(tmp, count + 1);
		char aval;
		char bval;
		if (i >= alen) {
			aval = 0;
		}
		else {
			aval = a[alen - i - 1] - '0';
		}
		if (i >= blen) {
			bval = 0;
		}
		else {
			bval = b[blen - i - 1] - '0';
		}
		somma = aval + bval + riporto;
		if (somma >= 10) {
			tmp[count] = somma % 10;
			riporto = somma / 10;
		}
		else {
			tmp[count] = somma;
			riporto = 0;
		}
		++count;
	}
	if (riporto != 0) {
		tmp = realloc(tmp, count + 1);
		tmp[count - 1] = somma % 10;
		tmp[count] = riporto;
		++count;
	}
	char* out = calloc(count + 1, 1);
	for (size_t i = 0; i < count; ++i) {
		out[i] = tmp[count - 1 - i] + '0';
	}
	free(tmp);
	return out;
}