#define _CRT_SECURE_NO_WARNINGS
#include "rectangle.h"

int main(void)
{
	FILE* f = fopen("file1.bin", "rb");
	if (f == NULL) {
		return NULL;
	}

	struct rect rettangolo;
	bool ris;
	ris = rect_load(f, &rettangolo);
	
	fclose(f);
	return 0;
}