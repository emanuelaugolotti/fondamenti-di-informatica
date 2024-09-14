#include "divisori.h"

unsigned int conta_divisori(unsigned int num, unsigned int max)
{
	unsigned int count = 0;
	unsigned div = 1;
	while (div <= num && div <= max) {
		if (num % div == 0) {
			++count;
		}
		++div;
	}
	return count;
}