#include <stdlib.h>
#include <stdio.h>

extern int* read_gruppi(const char* filename, size_t* ngruppi);

int main(void)
{
	int* ris;
	size_t n;
	ris = read_gruppi("prova.txt", &n);
	
	return 0;
}