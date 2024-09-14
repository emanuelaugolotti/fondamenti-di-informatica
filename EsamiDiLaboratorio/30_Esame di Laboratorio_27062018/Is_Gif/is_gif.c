#define _CRT_SECURE_NO_WARNINGS 
#include "is_gif.h"

bool is_gif(const char* filename)
{
	if (filename == NULL) {
		return false;
	}
	FILE* f = fopen(filename, "rb");
	if (!f) {
		return false;
	}
	char bufferLetto[7] = { 0 };
	size_t r = fread(bufferLetto, 1, 6, f);
	if (r != 6) {
		fclose(f);
		return false;
	}
	char gif1[] = "GIF89a", gif2[] = "GIF87a";
	if( !strcmp(bufferLetto, gif1) || !strcmp(bufferLetto, gif2)) {
		fclose(f);
		return true;
	}
	fclose(f);
	return false;
}