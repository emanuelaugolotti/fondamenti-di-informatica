#include <stdbool.h>
#include <stdint.h>

bool is_prime(uint32_t val) {
	if (val < 2) {
		return false;
	}
	for (uint32_t i = 2; i < val - 1; ++i) {
		if (val % i == 0) { 
			return false;
		}
	}
	return true;
}

bool goldbach(uint32_t n, uint32_t* p1, uint32_t* p2)
{
	//Se il numero non è pari e maggiore di 2, la funzione restituisce falseSe il numero non è pari e maggiore di 2, 
	//la funzione restituisce false.
	if (n <= 2) {
		return false;
	}
	if (n > 2 && (n % 2 != 0)) { //numero maggiore di due dispari
		return false;
	}

	//numeri maggiori di 2 pari
	uint32_t mid = n / 2;
	uint32_t secondo = mid;

	while (1) {
		if (is_prime(mid) && is_prime(secondo)) {
			*p1 = mid;
			*p2 = secondo;
			return true;
		}
		mid -= 1;
		secondo += 1;
	}
}