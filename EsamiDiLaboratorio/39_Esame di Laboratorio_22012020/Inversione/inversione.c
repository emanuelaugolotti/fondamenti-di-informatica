#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool inverti_case(const char* nomefilein, const char* nomefileout)
{
	if (nomefilein == NULL || nomefileout == NULL) {
		return false;
	}
	FILE* fin = fopen(nomefilein, "r");
	FILE* fout = fopen(nomefileout, "w");
	if (fin == NULL) {
		fclose(fout);
		return false;
	}
	if (fout == NULL) {
		fclose(fin);
		return false;
	}
	while (1) {
		int c = fgetc(fin);
		if (c == EOF) {
			break;
			}
		if (isalpha(c)) {
			if (islower(c)) {
				c = toupper(c);
			}
			else {
				c=tolower(c);
			}
		}
		fprintf(fout, "%c", c);
	}
	fclose(fin);
	fclose(fout);
	return true;
}
