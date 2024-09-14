#include <string.h>
#include <stdlib.h>

char* sostituisci(char* str, size_t Size, int c)
{
	str = realloc(str, Size + 1);
	str[Size - 1] = c;
	str[Size] = 0;
	return str;
}

char* change_font(const char* s)
{
	if (s == NULL) {
		return NULL;
	}
	char* out = calloc(1, 1);
	size_t size = 1;
	for (size_t i = 0; i < strlen(s); ++i) {
		if (strstr(s + i, "SEI") == s + i) {
			out = sostituisci(out, size, '6');
			++size;
			i += 2;
		}
		else if (strstr(s + i, "PER") == s + i) {
			out =sostituisci(out, size, 'X');
			++size;
			i += 2;
		}
		else if (s[i] == 'A') {
			out = sostituisci(out, size, '4');
			++size;
		}
		else if (s[i] == 'E') {
			out = sostituisci(out, size, '3');
			++size;
		}
		else if (s[i] == 'I') {
			out = sostituisci(out, size, '1');
			++size;
		}
		else if (s[i] == 'O') {
			out = sostituisci(out, size, '0');
			++size;
		}
		else if (s[i] == 'S') {
			out = sostituisci(out, size, '5');
			++size;
		}
		else {
			out = sostituisci(out, size, s[i]);
			++size;
		}
	}
	return out;
}