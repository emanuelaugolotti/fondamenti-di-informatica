#include <stdbool.h>

extern bool is_pangram(const char* sentence);

int main(void)
{
	bool ris;
	ris = is_pangram("Ma che bel gufo spenzola da quei travi");
	return 0;
}