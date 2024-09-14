#include <stdbool.h>

bool is_prime(unsigned int n)
{
	for (unsigned int i = 2; i < n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


bool is_ugly(unsigned int num)
{
	if (num == 0 || num == 1) {
		return false;
	}
	unsigned int i = 2;
	while (i <= num) {
		if (num % i == 0) {
			if (is_prime(i) == true) {
				if (i != 2 && i != 3 && i != 5) {
					return false;
				}
				else {
					num /= i;
					i = 1;
				}
			}
		}
		++i;
	}
	
	return true;
}