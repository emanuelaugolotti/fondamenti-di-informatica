#include <stdlib.h>
extern char* sottrai_stringhe(const char* a, const char* b);

int main(void)
{
	char a[] = "12345";
	char b[] = "12345";
	char* ris;
	ris = sottrai_stringhe(a, b);
	free(ris);
	return 0;
}