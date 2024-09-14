#include <stdlib.h>

extern char* farfallino_encode(const char* s);

int main(void)
{
	char* ris;
	ris = farfallino_encode("ciao");
	free(ris);
	
	return 0;
}