#include "imperial.h"

int main(void)
{
	char s[] = "2 mi. 2 yd. 2' 2\"";
	double ris;
	ris = to_meter(s);

	return 0;
}