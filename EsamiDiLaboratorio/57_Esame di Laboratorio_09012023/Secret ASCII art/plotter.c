#include <stdlib.h>
#include <stdio.h>

void plotter(const char* p)
{
	if (p == NULL) {
		return;
	}
	for (size_t i = 0; p[i] != 0; ++i) {
		if (p[i] < 0) {
			for (size_t j = 0; j < (size_t)(abs(p[i])); ++j) {
				printf("%c", p[i + 1]);
			}
			++i;
			continue;
		}
		if (p[i] > 0) {
			printf("%c", p[i]);
		} 
	}
	return;
}