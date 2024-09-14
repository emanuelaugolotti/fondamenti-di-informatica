#include <stdlib.h>
#include <stdbool.h>

bool maggiore(const int* s, size_t j) 
{
	for (size_t i = 0; i < j; ++i) {
		if (s[i] >= s[j]) {
			return false;
		}
	}
	return true;
}

bool minore(const int* s, size_t j, size_t num)
{
	for (size_t i = j + 1; i < num; ++i) {
		if (s[i] <= s[j]) {
			return false;
		}
	}
	return true;
}

size_t find_first_partition(const int* seq, size_t n)
{
	if (seq == NULL || n == 0) {
		return 0;
	}
	bool maggioreprecedenti = false;
	bool minoresuccessivi = false;
	size_t pos;
	for (size_t i = 0; i < n; ++i) {
		//seq[i] è il candidato
		if (i == 0) {
			maggioreprecedenti = true;
		}
		else {
			maggioreprecedenti = maggiore(seq, i);
		}
		if (i == n - 1) {
			minoresuccessivi = true;
		}
		else {
			minoresuccessivi = minore(seq, i, n);
		}
		if (maggioreprecedenti == true && minoresuccessivi == true) {
			pos = i;
			break;
		}
	}
	if (maggioreprecedenti == false || minoresuccessivi == false) {
		pos = n;
	}
	return pos;
}
