#include "angoli.h"

int main(void)
{
	struct angolo a = { 10, 255, 255 };
	struct angolo b = { 10, 255, 255 };

	struct angolo somma;
	somma = somma_angoli(a, b);
	
	return 0;
}