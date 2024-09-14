#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool presente(int lettera, const char* s)
{
	for (size_t i = 0; i < strlen(s); ++i) {
		if (tolower(s[i]) == lettera) {
			return true;
		}
	}
	return false;
}


bool is_pangram(const char* sentence)
{
	if (sentence == NULL || strlen(sentence) == 0) {
		return false;
	}
	for (int i = 'a'; i < 'j'; ++i) {
		if (presente(i, sentence) == false) {
			return false;
		}
	}
	for (int i = 'l'; i < 'w'; ++i) {
		if (presente(i, sentence) == false) {
			return false;
		}
	}
	if (presente('z', sentence) == false) {
		return false;
	}
	
	return true;
}
