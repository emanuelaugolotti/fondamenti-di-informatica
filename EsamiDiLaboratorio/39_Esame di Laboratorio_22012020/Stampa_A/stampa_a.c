#include <stdint.h>
#include <stdio.h>

void stampa(int c, uint8_t num)  //stampa un carattere num volte
{
	for (uint8_t i = 0; i < num; ++i) {
		printf("%c", c);
	}
	return;
}

void stampa_a(uint8_t n)
{
	if (n % 2 == 0 || n < 3) {
		return;
	}
	uint8_t spazi_est, spazi_int;
	for (uint8_t r = 0; r < n; ++r) {
		spazi_est = n - 1 - r;
		spazi_int = 2 * n - 2 - 2 * spazi_est;
		stampa(' ', spazi_est);
		printf("/");
		if (r == n / 2) {
			stampa('-', spazi_int);
		}
		else {
			stampa(' ', spazi_int);
		}
		printf("\\");
		stampa(' ', spazi_est);
		if (r != n - 1) {
			printf("\n");
		}
	}
	return;
}