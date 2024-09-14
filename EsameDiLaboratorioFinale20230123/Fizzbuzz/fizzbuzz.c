#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return 1;
	}
	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (*endptr != 0) {
		return 1;
	}
	if (n == 0) {
		return 1;
	}
	for (int r = 1; r <= n; ++r) {
		if (r % 3 == 0 && r % 5 != 0) {
			printf("Fizz");
		}
		else if (r % 5 == 0 && r % 3 != 0) {
			printf("Buzz");
		}
		else if (r % 3 == 0 && r % 5 == 0) {
			printf("Fizzbuzz");
		}
		else {
			printf("%i", r);
		}
		printf("\n");
	}
	return 0;
}