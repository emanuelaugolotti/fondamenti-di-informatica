#define _CRT_SECURE_NO_WARNINGS    //Esercizio fatto in classe durante la simulazione dell'esame
#include "is_gif.h"

bool is_gif(const char* filename)
{
	if (filename == NULL) {
		return false;
	}
	
	FILE *f = fopen(filename, "rb");
	if (f == NULL) {
		return false;
	}
	char* buffer = malloc(6 * sizeof(char));
	size_t r = fread(buffer, sizeof(char), 6, f);
	if (r != 6) {
		fclose(f);
		free(buffer);
		return false;
	}
	if ((buffer[0] == 'G' && buffer[1] == 'I' && buffer[2] == 'F' && buffer[3] == '8' && buffer[4] == '9' && 
		buffer[5]=='a') || (buffer[0] == 'G' && buffer[1] == 'I' && buffer[2] == 'F' && buffer[3] == '8' && 
		buffer[4] == '7')) {
		fclose(f);
		free(buffer);
		return true;
	}
	fclose(f);
	free(buffer);
	return false;
}