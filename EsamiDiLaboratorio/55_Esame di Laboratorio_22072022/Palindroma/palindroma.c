#include "palindroma.h"

bool palindroma(const char* str)
{
	if (str == NULL) {
		return false;
	}

	size_t len = strlen(str);

	if (len == 0) {
		return false;
	}

	char* copy;
	size_t count;
	if (len % 2 == 0) {  //Stringa pari
		count = len / 2;
	}
	else {  //Stringa dispari
		count = (len - 1) / 2;
	}
	copy = calloc(count + 1, 1);
	for (size_t i = 0; i < count; ++i) {
		copy[i] = str[len - 1 - i];
	}
	if (strncmp(str, copy, count)) {
		free(copy);
		return false;
	}
	else {
		free(copy);
		return true;
	}
}