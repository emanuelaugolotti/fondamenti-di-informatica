#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

extern void quadrati_progressivi(FILE* f, int n);

int main(void)
{
	FILE* f = fopen("prova.txt", "w");
	if (f == NULL) {
		return NULL;
	}

	quadrati_progressivi(f, 17);

	fclose(f);
	return 0;
}