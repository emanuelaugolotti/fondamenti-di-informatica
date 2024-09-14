#include <string.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return 1;
	}
	size_t len = strlen(argv[1]);
	int ternario = 0;
	for (size_t i = 0; i < len; ++i) {
		switch (argv[1][i])
		{
		case '+': {
			ternario += (int)pow(3, (double)(len - i - 1));
			break;
		}
		case '-': {
			ternario -= (int)pow(3, (double)(len - i - 1));
			break;
		}
		case'0': break;
		default: return 1;
		}
	}
	printf("%i\n", ternario);
	return 0;
}