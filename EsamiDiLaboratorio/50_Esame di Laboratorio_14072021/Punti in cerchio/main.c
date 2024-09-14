#include "punti_in_cerchio.h"

int main(void)
{
	struct punto v[] = { {5, 1},  {4, 3.7},  {6.3, 8} };
	struct punto* ris;
	size_t count;
	ris = punti_in_cerchio(v, 3, 2.0, &count);
	free(ris);
	
	return 0;
}