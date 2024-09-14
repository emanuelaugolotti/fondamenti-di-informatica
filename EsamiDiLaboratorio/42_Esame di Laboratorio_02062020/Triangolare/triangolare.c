#include <stdbool.h>

bool triangolare(int n)
{
	if (n <= 0) {
		return false;
	}
	
	int count = 0;
	for (int i = 1; count <= n; ++i) {
		count += i;
		if (count == n) {
			return true;
		}
	}

	return false;
}