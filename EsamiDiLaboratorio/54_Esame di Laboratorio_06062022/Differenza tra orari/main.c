#include "orari.h"

int main(void)
{
	struct orario ora1 = { 23, 36, 4 };
	struct orario ora2 = { 15, 47, 12 };
	
	struct orario diff;
	diff = differenza_orari(ora1, ora2);

	return 0;
}