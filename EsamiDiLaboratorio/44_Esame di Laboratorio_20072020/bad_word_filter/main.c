#include <stdlib.h>

void bad_word_filter(char* s, char** words, size_t nwords);

int main(void)
{
	char s[] = "Il tuo cavolfiore e` molto broccolo, si' e' propio un broccolo";
	char* words[] = { "carciofo", "broccolo", "cavolfiore" };
	size_t dimensione = 3;
	bad_word_filter(s, words, dimensione);
	
	return 0;
}