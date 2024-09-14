#include <stdio.h>

void stampa_carattere(int c, int num) {
	for (int i = 0; i < num; ++i) {
		printf("%i ", c);
	}
	return;
}

void stampa_riga(int ripetuto, int nonripetuti, int num) 
{
	int stampa = num;
	for (int i = 0; i < nonripetuti; ++i) {
		stampa_carattere(stampa % 10, 1);
		--stampa;
	}
	stampa_carattere(stampa % 10, ripetuto);
	++stampa;
	for (int i = 0; i < nonripetuti; ++i) {
		stampa_carattere(stampa % 10, 1);
		++stampa;
	}
	printf("\n");  //fine riga
	return;
}

void stampa_quadrati_concentrici(int n)
{
	//Qualora la funzione riceva un valore di n non positivo, non invia nulla in output.
	if (n <= 0) {
		return;
	}
	if (n == 1) {
		printf("%i", n);
		return;
	}
	int count = 2 * n - 1; //count = numero elementi di una riga = numero righe
	int rip, nonrip;
	//stampo metà superiore del quadrato
	for (int riga = 0; riga < (count / 2) + 1; ++riga) {
		rip = count - 2 * riga;
		nonrip = (count - rip) / 2;
		stampa_riga(rip, nonrip, n);
	}
	//stampo metà inferiore del quadrato
	for (int riga = (count / 2) - 1; riga >= 0; --riga) {
		rip = count - 2 * riga;
		nonrip = (count - rip) / 2;
		stampa_riga(rip, nonrip, n);
	}
	return;
}