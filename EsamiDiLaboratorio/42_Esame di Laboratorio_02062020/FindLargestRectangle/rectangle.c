#include "rectangle.h"

int find_largest(const struct rect* r, size_t n)
{
	//Se r è NULL o n=0, la funzione restituisce -1.
	if (r == NULL || n == 0) {
	return -1;
	}

	int maxindice;
	int maxarea = 0;
	for (size_t i = 0; i < n; ++i) {
		int area = (r[i].a.y - r[i].b.y) * (r[i].b.x - r[i].a.x);
		if (area < 0) {
			area *= (-1);
		}
		if (area > maxarea) {
			maxarea = area;
			maxindice = (int)i;
		}
	}
	
	return maxindice;
}