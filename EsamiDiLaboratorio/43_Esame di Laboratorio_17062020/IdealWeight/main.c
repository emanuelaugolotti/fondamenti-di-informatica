#include "weight.h"

int main(void)
{
	double ris;
	ris = ideal_weight(169, 34, 'F', lorenz);
	ris = ideal_weight(169, 34, 'F', keys);
	ris = ideal_weight(169, 34, 'F', berthean);
	return 0;
}