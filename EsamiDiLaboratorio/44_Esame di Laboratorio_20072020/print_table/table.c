#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void riga1Print(uint8_t num)
{
	for (uint8_t i = 0; i < num; ++i) {
		printf("+---------");
	}
	printf("+");
}

void riga2Print(uint8_t num, char *s)
{
	for (uint8_t i = 0; i < num; ++i) {
		printf("|%-9s", s);
	}
}

void print_table(char** colnames, uint8_t ncols, uint8_t nrows)
{
	if (ncols == 0 || nrows == 0 || colnames == NULL) {
		return;
	}
	for (uint8_t i = 0; i < ncols; ++i) {
		riga2Print(1, colnames[i]);
	}
	printf("|\n");
	for (uint8_t i = 0; i < nrows; ++i) {
		riga1Print(ncols);
		printf("\n");
		riga2Print(ncols, "");
		printf("|\n");
	}
	riga1Print(ncols);
	return;
}