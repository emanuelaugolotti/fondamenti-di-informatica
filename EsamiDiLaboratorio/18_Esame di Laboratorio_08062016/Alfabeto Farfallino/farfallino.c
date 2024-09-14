#include <stdlib.h>

char* farfallino_encode(const char* s)
{
	if (s == NULL) {
		return NULL;
	}

	char* buffer = malloc(1);
	size_t pos = 0;
	for (size_t i = 0; s[i] != 0; ++i) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			buffer = realloc(buffer, pos + 4);
			buffer[pos] = s[i];
			buffer[pos + 1] = 'f';
			buffer[pos + 2] = s[i];
			pos += 3;
		}
		else {
			buffer = realloc(buffer, pos + 2);
			buffer[pos] = s[i];
			++pos;
		}
	}
	
	buffer[pos] = 0;  //terminatore

	return buffer;
}