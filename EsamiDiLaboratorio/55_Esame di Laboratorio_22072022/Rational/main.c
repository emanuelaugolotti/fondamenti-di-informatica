#include "rational.h"

int main(void)
{
	size_t frazioniLette;

	struct rational* frazRis = rational_read("file2.txt", &frazioniLette);
	free(frazRis);

	return 0;
}