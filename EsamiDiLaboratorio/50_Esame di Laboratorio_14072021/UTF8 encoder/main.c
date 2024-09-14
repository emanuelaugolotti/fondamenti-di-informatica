#include "utf8.h"

int main(void)
{
	uint8_t v[4] = { 0 };
	size_t nByte = utf8_encode(0x00010348, v);
	
	return 0;
}