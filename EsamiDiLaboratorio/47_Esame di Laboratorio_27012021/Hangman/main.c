extern char* hangman(const char* frase, const char* lettere);

int main(void)
{
	char Frase[] = "Sopra la panca la capra campa, sotto la panca la capra crepa.";
	char Lettere[] = "";
	char* ris;
	ris = hangman(Frase, Lettere);

	free(ris);
	return 0;
}