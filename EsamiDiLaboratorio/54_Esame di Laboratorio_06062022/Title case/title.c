#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i) {  //considero l'i-esimo parametro
		size_t len = strlen(argv[i]);  //len è la lunghezza del parametro i-esimo

		for (size_t crt = 0; crt < len; ++crt) { //scorro la stringa considerata carattere per carattere
			if (argv[i][crt] != ' ' && (crt != len - 1)) {
				printf("%c", argv[i][crt]);
			}
			if (crt == len - 1 && (argv[i][crt] != ' ')) {  //ultimo elemento della stringa i-esima
				if (isalpha(argv[i][len - 1]) && islower(argv[i][len - 1])) {
					argv[i][len - 1] = toupper(argv[i][len - 1]);
				}
				printf("%c", argv[i][crt]);
			}
		}
		if (i != argc - 1) {  //se non è l'ultima stringa
			printf(" "); //separo le stringhe tra di loro con uno spazio
	    }
	}
	printf("\n");

	return 0;
}