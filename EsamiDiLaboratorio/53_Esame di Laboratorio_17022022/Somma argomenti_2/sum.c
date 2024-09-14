#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int somma = 0;
	for (int i = 1; i < argc; ++i) {
		char* endptr;
		int n = strtol(argv[i], &endptr, 10);
		if (*endptr == 0) {
			somma += n;
		}
	}
	printf("%i\n", somma);
	return 0;
}