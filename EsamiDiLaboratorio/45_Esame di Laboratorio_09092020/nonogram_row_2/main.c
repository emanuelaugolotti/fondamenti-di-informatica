#include <stdlib.h>
#include <stdint.h>

extern uint8_t* nonogram_row(const char* s, size_t* n);

int main(void)
{
	uint8_t* ris;
	char str[] = "";
	size_t num;
	ris = nonogram_row(str, &num);
	
	//libero la memoria
	free(ris);
	return 0;
}