#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool cercainfrom(const char* from, char c)
{
	for (size_t i = 0; i < strlen(from); ++i) {
		if (from[i] == c) {
			return true;
		}
	}
	return false;
}

size_t indice(const char* from, char c)
{
	for (size_t i = 0; i < strlen(from); ++i) {
		if (from[i] == c) {
			return i;
		}
	}
}

void translate(char* str, const char* from, const char* to)
{
	if (str == NULL || from == NULL || to == NULL) {
		return;
	}
	if (strlen(from) != strlen(to)) {
		return;
	}
	for (size_t i = 0; i < strlen(str); ++i) {
		if (cercainfrom(from, str[i]) == true) {
			size_t pos = indice(from, str[i]);
			str[i] = to[pos];
		}
	}
	return;
}