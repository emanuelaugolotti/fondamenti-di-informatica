#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int scrivi_conta_caratteri(FILE* f, const char* s)
{
//Se, per qualsivoglia motivo, la funzione non scrive nessun elemento sul file, essa quindi restituisce 0.
	if (s == NULL) {
		return 0;
	}
	int len = (int)strlen(s);  //lunghezza stringa
	if (len == 0) {  //stringa s vuota
		fprintf(f, "\n\n");
		return 0;
	}
	for (int i = 0; i < len; ++i) {
		int c = fputc(s[i], f);
		if (c != s[i]) {
			break;
		}
	}
	fprintf(f, "\n");
	unsigned int scrivi = 1;
	for (int i = 0; i < len; ++i) {
		fprintf(f, "%u", scrivi);
		++scrivi;
		if (scrivi > 9) {
			scrivi = 0;
		}
	}
	fprintf(f, "\n");
	return len;  //ritorna il numero di caratteri della stringa s correttamente scritti su file
}