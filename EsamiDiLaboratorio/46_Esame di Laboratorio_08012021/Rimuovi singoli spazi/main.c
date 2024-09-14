#include <stdlib.h>
extern char* rimuovi_singoli_spazi(const char* s);

int main(void)
{
	char s[] = " ";
	char* ris;
	ris = rimuovi_singoli_spazi(s);
	free(ris);
	
	return 0;
}