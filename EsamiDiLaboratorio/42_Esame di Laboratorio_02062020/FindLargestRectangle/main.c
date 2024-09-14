#include "rectangle.h"

int main(void)
{
	struct rect v[] = { {{ -79,4},{94,-91}}, {{-9, 35}, {-18,17}} };
	int ris;
	ris = find_largest(v, 2);
	
	return 0;
}