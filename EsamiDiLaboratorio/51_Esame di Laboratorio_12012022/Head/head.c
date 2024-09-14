#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return 1; //scrittura non completata
	}
	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		return 1; //scrittura non completata
	}
	unsigned int count_righe = 0;
	char* buffer = NULL;
	unsigned int count = 0; //contatore caratteri di una riga
	while (count_righe < 10) {
		int c = fgetc(f);
		if (c == EOF) {
			break;
		}
		++count;
		buffer = realloc(buffer, count + 1);
		buffer[count - 1] = c;
		if (c == '\n') {
			++count_righe;
			buffer[count] = 0;
			printf("%s", buffer);
			count = 0;
		}
	}
	if (count_righe < 10) {
		buffer[count] = 0;
		printf("%s\n", buffer);
	}
	free(buffer);
	fclose(f);
	return 0; //scrittura completata
}