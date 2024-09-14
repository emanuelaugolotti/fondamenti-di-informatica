#include <stdbool.h>
#include <stdint.h>

extern bool primigemelli(uint32_t start, uint32_t* x, uint32_t* y);

int main(void)
{
	uint32_t x, y;
	bool ris = primigemelli(4294965673, &x, &y);
	
	return 0;
}