#include "segmento.h"

int main(void)
{
	struct segmento *ris;
	struct segmento seg1 = { 1,4 };
	struct segmento seg2 = { 3,5 };
	ris = intersezione(seg1, seg2);
	
	free(ris);
	return 0;
}