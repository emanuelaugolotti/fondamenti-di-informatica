#include "rapporti.h"

int main(void)
{
	uint16_t numerorapporti;
	struct rapporto* ris;
	ris = leggi_rapporti("rapporto2.bin", &numerorapporti);
	
	//fare la free
	free(ris);
	return 0;
}