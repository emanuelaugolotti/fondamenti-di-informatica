#include <stdlib.h>
extern size_t find_first_partition(const int* seq, size_t n);

int main(void)
{
	int seq[] = { 1, 1, 4, 3, 6, 8, 10, 7, 9 };
	size_t ris;
	ris = find_first_partition(seq, 9);
	
	return 0;
}

