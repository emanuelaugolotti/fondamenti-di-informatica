#include <stdlib.h>
#include <limits.h>
#include <string.h>

int roll_and_keep(const int* r, size_t x, size_t y)
{
	//Se r è NULL, se x = 0 o y = 0 o y > x, la funzione ritorna 0.
	if (r == NULL || x == 0 || y == 0) {
		return 0;
	}

	int* buffer = malloc(y * sizeof(int));
	memset(buffer, INT_MIN, y * sizeof(int));
	int somma = 0;
	size_t count = 0;
	int max = INT_MIN;
	while (count < y) {
		for (size_t i = 0; i < x; ++i) {
			if (r[i] > max && (memchr(buffer,r[i],y * sizeof(int)) == NULL)) {
				max = r[i];
			}
		}
		somma += max;
		buffer[count] = max;
		++count;
		max = INT_MIN;
	}
	free(buffer);
	return somma;
}