#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern void scrivi_v(FILE* f, uint8_t n);

int main(void)
{
	FILE* f = fopen("prova.txt", "w");
	if (f == NULL) {
		return 1;
	}
	
	scrivi_v(f, 7);
	
	return 0;
}