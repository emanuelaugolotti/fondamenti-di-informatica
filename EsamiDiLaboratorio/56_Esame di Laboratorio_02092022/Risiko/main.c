#include "risiko.h"

int main(void)
{
	struct lancio attacco = { { 5, 3 }, 2 };
	struct lancio difesa = { { 4, 3 }, 2 };

	char perseAttacco, perseDifesa;

	confronta_lanci(&attacco, &difesa, &perseAttacco, &perseDifesa);
	
	return 0;
}