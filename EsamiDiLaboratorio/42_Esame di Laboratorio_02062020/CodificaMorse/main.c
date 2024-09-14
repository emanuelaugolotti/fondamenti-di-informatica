#include <stdlib.h>
extern char* codifica_morse(const char* testo);

int main(void)
{
	char s[] = "CIAO MAMMA";
	char* ris;
	ris = codifica_morse(s);
	free(ris);
	
	return 0;
}