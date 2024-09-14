#include <stdbool.h>
#include <stdlib.h>

extern bool is_arithmetic(const int* v, size_t n);

int main(void)
{
	bool ris;
	int v[] = { 9, 7, 5, 3, 3 };
	ris = is_arithmetic(v, 5);
	
	return 0;
}