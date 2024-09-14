#include "punto.h"

int main(void)
{
	struct punto_cart p1 = { 2.0, 1.0 };
	struct punto_pol p2 = { 3.0, 7.0 };

	struct punto_pol p1out;
	struct punto_cart p2out;
	
	p1out = cartesiano2polare(&p1);
	p2out = polare2cartesiano(&p2);
	
	return 0;
}