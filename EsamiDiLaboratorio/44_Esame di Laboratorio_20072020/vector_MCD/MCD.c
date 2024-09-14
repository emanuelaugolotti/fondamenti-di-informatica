#include <stdint.h>
#include <stdlib.h>

uint32_t calcolaMCDtra2numeri(uint32_t a, uint32_t b)
{
	uint32_t tmp;
	while (a != b ) {
		if (a < b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		tmp = a - b;
		a = tmp;
	}
	return a;
}

uint32_t vector_MCD(const uint32_t* v, size_t n)
{
	if (v == NULL || n == 0 || v[0] == 0) {
		return 0;
	}
	uint32_t MCD = v[0];
	for (size_t i = 1; i < n; ++i) {
		if (v[i] == 0) {
			return 0;
		}
		MCD = calcolaMCDtra2numeri(v[i], MCD);
	}
	return MCD;
}