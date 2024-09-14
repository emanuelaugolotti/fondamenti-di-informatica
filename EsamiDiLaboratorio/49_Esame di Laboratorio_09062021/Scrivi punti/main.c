#define _CRT_SECURE_NO_WARNINGS
#include "WTK.h"

int main(void)
{
	FILE* f = fopen("prova.txt", "w");
	if (f == NULL) {
		return NULL;
	}
	
	struct point v[] = { {5,1},{4,3.7},{6.3,8} };
	size_t ris;
	ris = write_points(f, v, 3);

	fclose(f);
	return 0;
}