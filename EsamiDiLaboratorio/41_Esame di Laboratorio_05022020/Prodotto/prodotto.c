#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int prodotto_altri_due(const int* v, size_t n)
{
	if (v == NULL || n == 0) {
		return -1;
	}

	int count = 0;
	for (size_t i = 0; i < n; ++i) {
		int candidato = v[i];
		bool trovato = false;
		for (size_t j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}
			int elemento = v[j];
			for (size_t k = 0; k < n; ++k) {
				if (k == j || k == i) {
					continue;
				}
				int prodotto = elemento * v[k];
				if (prodotto==candidato)  {
					++count;
					trovato = true;
					break;
				}
			}
			if (trovato == true) {
				break;
			}
		}
    }
	return count;
}