#include <string.h>
#include <stdlib.h>

char* rimuovi_singoli_spazi(const char* s)
{
	if (s == NULL)
	{
		return NULL;
	}
	char* out = NULL;
	size_t count = 0;
	size_t len = strlen(s);
	for (size_t i = 0; i < len; ++i) {
		if (s[i] != ' ') {
			out = realloc(out, count + 1);
			out[count] = s[i];
			++count;
		}
		else if ((s[i] == ' ' && s[i + 1] == ' ' && i + 1 <= len ) || 
			(s[i] == ' ' && s[i - 1] == ' ' && s[i + 1] != ' ' && i - 1 <= len && i + 1 <= len)
			|| (s[i] == ' ' && s[i + 1] == 0 && s[i - 1] == ' ' && i + 1 <= len && i - 1 <= len)) {
			out = realloc(out, count + 1);
			out[count] = ' ';
			++count;
		}
	}
	out = realloc(out, count + 1);  //realloc per il terminatore
	out[count] = 0;
	return out;
}