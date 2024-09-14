#include <stdbool.h>
#include <stdint.h>

bool is_prime(unsigned long long n)
{
	if (n < 2) {
		return false;
	}
	for (unsigned long long i = 2; i < n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

unsigned long long prox_primo(unsigned long long n)
{
	unsigned long long prox = n + 1;
	while (!is_prime(prox)) {
		++prox;
	}
	return prox;
}

bool primigemelli(uint32_t start, uint32_t* x, uint32_t* y)
{
	unsigned long long inizio = start, prox = start;
	
	if (!is_prime(inizio)) {
		inizio = prox_primo(prox);
		if (inizio > UINT32_MAX) {
			return false;
		}
	}
	
	prox = inizio + 2;
	while (!is_prime(prox)) {
		inizio = prox_primo(inizio);
		if (prox > UINT32_MAX) {
			return false;
		}
		prox = inizio + 2;
	}
	/*while (prox - inizio != 2) {
		inizio = prox;
		prox = prox_primo(inizio);
		if (prox > UINT32_MAX) {
			return false;
		}
	}*/
	
	*x = (uint32_t)inizio;
	*y = (uint32_t)prox;
	return true;
}
