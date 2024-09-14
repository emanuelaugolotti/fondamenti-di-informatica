#include <stdint.h>
#include <stdlib.h>

extern uint8_t* nonogram_row(const char* s, size_t* n);
int main(void)
{
	char str[] = " * ****  **";
	size_t size;
	uint8_t* ris = nonogram_row(str, &size);
	
	free(ris);
	return 0;
}