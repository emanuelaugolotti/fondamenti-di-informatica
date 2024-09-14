#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t* nonogram_row(const char* s, size_t* n)
{
	if (s == NULL || n == NULL) {
		return NULL;
	}
	uint8_t* out = calloc(1, 1);
	size_t size = 0;
	if (strlen(s) == 0) {
		return out;
	}
	for (size_t i = 0; i < strlen(s); ++i) {
		if (s[i] == '*') {
			uint8_t count = 0;
			while (s[i] != ' ' && i < strlen(s)) {
				++count;
				++i;
			}
			out = realloc(out, size + 1);
			out[size] = count;
			--i;
			++size;
		}
	}
	*n = size;
	return out;
}