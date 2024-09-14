#include <stdlib.h>
#include <crtdbg.h>

extern char* decodifica_morse(const char* codice);

int main(void)
{
	char codice[] = "_._. .. ._ ___ / __ ._ __ __ ._";
	char* ris;
	ris = decodifica_morse(codice);
	
	free(ris);
	_CrtDumpMemoryLeaks();
	return 0;
}