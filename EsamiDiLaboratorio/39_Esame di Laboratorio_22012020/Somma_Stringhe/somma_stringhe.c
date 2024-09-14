#include <stdlib.h>
#include <string.h>

char* somma_stringhe(const char* a, const char* b)
{
	if (a == NULL || b == NULL) {
		return NULL;
	}
	char* out = NULL;
	unsigned long long val1, val2, somma = 0;
	val1 = strtoull(a, NULL, 10);
	val2 = strtoull(b, NULL, 10);
	if (val1 == 0 && val2 == 0) {
		out = calloc(2, 1 * sizeof(char));
		return out;
	}
	somma = val1 + val2;
	unsigned long long count = 0; //conta il numero di cifre
	while (somma != 0) {
		out = realloc(out, (count + 1) * sizeof(char));
		out[count] = (somma % 10) + '0';
		somma /= 10;
		++count;
	}
	char* copia = calloc(count + 1, sizeof(char));
	for (unsigned long long i = 0; i < count; ++i) {
		copia[i] = out[count - 1 - i];
	}
	free(out);
	return copia;
}