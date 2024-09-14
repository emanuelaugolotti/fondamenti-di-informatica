#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int consecutivo(const int* vec, size_t size, int num)
{
	int candidato = num + 1;
	size_t count = 0;
	while (count < size) {
		for (size_t i = 0; i < size; ++i) {
			if (vec[i] == candidato) {
				return candidato;
			}
		}
		++candidato;
		++count;
	}
	return num;
}

bool is_arithmetic(const int* v, size_t n)
{
	if (v == NULL || n < 2) {
		return false;
	}
	int next, prec = INT_MAX, diff;
	for (size_t i = 0; i < n; ++i) {
		if (v[i] < prec) {
			prec = v[i];
		}
	}
	next = consecutivo(v, n, prec);
	diff = next - prec;
	prec = next;
	for (size_t i = 2; i < n; ++i) {
		next = consecutivo(v, n, prec);
		if (next == prec && diff != 0) {
			return false;
		}
		if (next - prec != diff) {
			return false;
		}
		prec = next;
	}
	return true;
}