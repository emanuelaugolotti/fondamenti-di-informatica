#include <stdlib.h>
#include <string.h>

void sostituisci(char* str, char* bad)
{
	size_t len = strlen(bad);
	for (size_t i = 0; i < len; ++i) {
		str[i] = '*';
	}
}

void bad_word_filter(char* s, char** words, size_t nwords)
{
	if (s == NULL || words == NULL) {
		return;
		}
	for (size_t i = 0; i < nwords; ++i) {
		char* p = strstr(s, words[i]);
		while (p != NULL) {
			sostituisci(p, words[i]);
			p = strstr(p, words[i]);
		}
	}
	return;
}