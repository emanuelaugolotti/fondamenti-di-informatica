#define _CRT_SECURE_NO_WARNINGS
#include "variant.h"

int main(void)
{
	FILE* f = fopen("file2.variant", "rb");
	if (f == NULL) {
		return NULL;
	}
	char tipo;
	char* buffer = malloc(30);
	buffer = read_variant(f, &tipo);
	fclose(f);
	//libero la memoria
	return 0;
}