#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned int contalettere(const char* nomefile)
{
	FILE* f = fopen(nomefile, "r");
	if (f == NULL) {
		return 0;
	}

	unsigned int count = 0;
	while (1) {
		int c = fgetc(f);
		if (c == EOF) {
			break;
		}
		if (isalpha(c)) {
			++count;
		}
	}
	
	fclose(f);
	return count;
}