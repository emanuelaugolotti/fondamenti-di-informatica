#include <stdio.h>
#include <string.h>
#include <ctype.h>

void scrivistringa(char* s)
{
	size_t len = strlen(s);
	for (size_t i = 0; i < len; ++i) {
		if (i == len - 1) {
			s[i] = toupper(s[i]);
		}
		printf("%c", s[i]);
	}
}

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i) {
		scrivistringa(argv[i]);
		if (i != argc - 1) {
			printf(" ");
		}
	}
	printf("\n"); 
	return 0;
}