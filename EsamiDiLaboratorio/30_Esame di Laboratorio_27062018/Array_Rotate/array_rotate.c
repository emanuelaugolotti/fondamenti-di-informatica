#include <stdlib.h>
#include <math.h>

int* rotate(const int* vec, size_t len, size_t r)
{
	if (vec == NULL) {
		return NULL;
	}
	int* out = calloc(len, sizeof(int));
	for (size_t i = 0; i < len; ++i) {
		size_t end = r + i; //posizione dell'elemento dopo lo spostamento
		if (end > len - 1) {
			while (end - len > len - 1) {
				end -= len;
			}
			out[end - len] = vec[i];
		}
		else {
			out[i + r] = vec[i];
		}
	}
	return out;
}