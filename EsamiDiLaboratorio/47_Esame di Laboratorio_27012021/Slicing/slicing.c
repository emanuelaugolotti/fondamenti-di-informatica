#include <stdlib.h>

int* slicing(const int* v, size_t* n, size_t start, size_t end, int step)
{
	if (v == NULL || n == NULL || step == 0) {
		return NULL;
	}
	
	int* buffer = NULL;
	size_t count = 0;
	if (step > 0) {
		size_t pos = start;
		for (size_t i = start; i < end + 1; ++i) {
			if (i == pos) {
				++count;
				buffer = realloc(buffer, count * sizeof(int));
				buffer[count - 1] = v[i];
				pos += step;
			}
		}
	}
	else {
		size_t pos = end;
		for (size_t i = end; i > start - 1; --i) {
			if (i == pos) {
				++count;
				buffer = realloc(buffer, count * sizeof(int));
				buffer[count - 1] = v[i];
				pos += step;
			}
		}
	}
	*n = count;
	return buffer;
}