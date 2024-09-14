#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int intero(char* ptr) {
	if (ptr[0] != '+' && ptr[0] != '-' && !isdigit(ptr[0])) {
		return 0;
	}
	for (unsigned int i = 1; ptr[i] != 0; ++i) {
		if (!isdigit(ptr[i])) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char* argv[])
{
	if (argc == 1) {
		printf("0\n");
		return 0;
	}
	//Ignorare tutti i parametri che NON sono numeri interi espressi come testo in base 10.
	int somma = 0;
	int val;
	for (int i = 1; i < argc; ++i) {  //Scorro tutti i parametri
		//Considero il puntatore argv[i]
		char* endptr;
		if (intero(argv[i])) {     
			val = strtol(argv[i], &endptr, 10);
			somma += val;
		}
}
	printf("%i\n", somma);
	return 0;
}