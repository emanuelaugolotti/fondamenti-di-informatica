#include "unpack.h"

void unpack_values(uint32_t pack, uint16_t* num1, uint16_t* num2, uint16_t* num3)
{
	*num1 = pack % (uint16_t)exp2(10);
	*num2 = (pack / (uint16_t)exp2(10)) % (uint16_t)exp2(10);
	*num3 = ((pack / (uint16_t)exp2(10)) / (uint16_t)exp2(10)) % (uint16_t)exp2(10);

	return;
}