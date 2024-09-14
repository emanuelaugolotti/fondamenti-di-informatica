#include <stdbool.h>
#include <stdint.h>

extern bool goldbach(uint32_t n, uint32_t* p1, uint32_t* p2);

int main(void)
{
	uint32_t intero1 = 0;
	uint32_t intero2 = 0;
	
	goldbach(113632822, &intero1, &intero2);
	goldbach(6, &intero1, &intero2);
	goldbach(8, &intero1, &intero2);
	goldbach(10, &intero1, &intero2);
	goldbach(12, &intero1, &intero2);
	goldbach(14, &intero1, &intero2);
	goldbach(4, &intero1, &intero2);
	
	return 0;
}