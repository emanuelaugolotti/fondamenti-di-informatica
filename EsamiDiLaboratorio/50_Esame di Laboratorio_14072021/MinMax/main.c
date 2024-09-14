#include <stdlib.h>

extern void minmax(const int* v, size_t n, int* min, int* max);

int main(void)
{
	int v[] = { 1,-2,3,4,5,5 };
	int min, max;
	minmax(v, 6, &min, &max);

	return 0;
}