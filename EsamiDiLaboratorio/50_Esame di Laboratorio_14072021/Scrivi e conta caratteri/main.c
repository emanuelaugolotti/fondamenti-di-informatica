#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int scrivi_conta_caratteri(FILE* f, const char* s);

int main(void)
{
	FILE* f = fopen("prova.txt", "w");
	char s[] = "scrivimi su file per completare l'esercizio.";
	int num;
	num = scrivi_conta_caratteri(f, s);

	fclose(f);
	return 0;
}