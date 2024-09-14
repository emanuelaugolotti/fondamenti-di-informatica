#include <stdint.h>
#include <stdio.h>
void printSup(uint8_t n) 
{
	for (uint8_t i = 0; i < n - 1; ++i) {
		printf("/-\\");
		printf("|");
	}
	printf("/-\\\n");
}

void printInf(uint8_t n) 
{
	for (uint8_t i = 0; i < n - 1; ++i) {
		printf("\\-/");
		printf("|");
	}
	printf("\\-/");
}

void printRiga(uint32_t n, uint32_t c1, uint32_t c2)
{
	printf("%c",c1);
	for (uint32_t i = 0; i < n; ++i) {
		printf(" ");
	}
	printf("%c\n", c2);
}

void cornice(uint8_t h, uint8_t w)
{
	if (h == 0 || w == 0) {
		return;
	}
	printSup(w);
	uint32_t num = 4 * w - 3;
	uint8_t nTrattini = 0;
	printRiga(num, '|', '|');
	if (h != 1) {
		printRiga(num, '\\', '/');  //num è il numero di spazi
		printRiga(num, '-', '-');
		++nTrattini;
		for (uint8_t i = 0; i < (h - 2); ++i) {
			printRiga(num, '/', '\\');
			printRiga(num, '|', '|');
			printRiga(num, '\\', '/');
			if (nTrattini < h - 1) {
				printRiga(num, '-', '-');
			}
		}
		printRiga(num, '/', '\\');
		printRiga(num, '|', '|');
	}
	printInf(w);
	return;
}