#include <stdint.h>

extern void print_table(char** colnames, uint8_t ncols, uint8_t nrows);

int main(void)
{
	char* nomicolonne[] = { "cat", "dog", "deer", "frog", "bear"};
	print_table(nomicolonne, 5, 7);
	
	return 0;
}