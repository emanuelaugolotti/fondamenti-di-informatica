#include "byteswap.h"

uint32_t byteswap(uint32_t n)
{
	uint32_t val1, val2, val3, val4;
	val1 = (n % 256) << 24;
	val2 = ((n / 256) % 256) << 16;
	val3 = (n / (256 * 256)) % 256 << 8;
	val4 = (n / (256 * 256 * 256)) % 256;

	return val1 + val2 + val3 + val4 ;
}