#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 2) { //numero parametri passati non corretto
		return 1;
	}
	
	FILE* f = fopen(argv[1], "r");
	if (f == NULL){
		return 1;
	}

	char* buffer = NULL;
	int count = 0;
	while (1) {
		int c = fgetc(f);
		if (c == EOF) {
			break;
		}
		buffer = realloc(buffer, count + 2);
		buffer[count] = (char)tolower(c);
		++count;
	}
	buffer[count] = 0; //metto il terminatore
	printf("%s", buffer);
	return 0;  //scrittura completata
}
