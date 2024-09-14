#include "read_dvec.h"

int main(void)
{
	struct dvec *ris;
	ris = read_dvec_comp("1.dvec");
	
	free(ris->d);
	free(ris);
	
	return 0;
}