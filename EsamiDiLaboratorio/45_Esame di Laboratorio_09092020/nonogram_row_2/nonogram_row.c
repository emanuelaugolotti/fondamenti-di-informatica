#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t* nonogram_row(const char* s, size_t* n)
{
	if (s == NULL || n == NULL) {
		return NULL;
	}
	uint8_t* out = calloc(1, 1);
	int n_spazi = 0, count = 0, size = 0, n_asterischi = 0;
	while (*(s + count) != 0) {
		sscanf(s + count, "%*[ ]%n", &n_spazi);
		count += n_spazi;
		if (*(s + count) == 0) {
			break;
		}
		sscanf(s + count, "%*[*]%n", &n_asterischi);
		count += n_asterischi;
		if (n_asterischi != 0) {
			out = realloc(out, (size + 1) * sizeof(char));
			out[size] = n_asterischi	;
			++size;
		}
	}
	*n = size;
	return out;
}