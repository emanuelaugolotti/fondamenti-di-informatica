#include <stdbool.h>
#include <stdio.h>

extern bool inverti_case(const char* nomefilein, const char* nomefileout);

int main(void)
{
	bool ris;
	ris = inverti_case("in1", "prova.txt");
	
	return 0;
}