#include <stdbool.h>
#include <stdint.h>

bool is_perfect(uint32_t n)
{
	if (n == 0 || n == 1) {
		return false;
	}
	uint32_t somma = 0;
	for (uint32_t i = 1; i < n; ++i) {
		if ((n % i) == 0) {  //è un divisore
			somma += i;
		}
	}
	if (somma == n) {
		return true;
	}
	else {
		return false;
	}
}