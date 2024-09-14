#include <stdlib.h>
#include <string.h>

extern char* somma_stringhe(const char* a, const char* b);

int main(void)
{
	char a[] = "12345678901234567890";
	char b[] = "98765432109876543210";
	char* ris;
	ris = somma_stringhe(a, b);
	
	free(ris);
	return 0;
}