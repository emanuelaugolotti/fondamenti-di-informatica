#include "unico.h"

const struct oggetto* unico(const struct carta* c)
{
	size_t pos = 0;
	do {
		size_t countForma = 0, countColore = 0;
		for (size_t i = 0; i < c->n; ++i) {
			if (strcmp(c->disegni[pos].forma, c->disegni[i].forma) == 0) {
				++countForma;
			}
			if (strcmp(c->disegni[pos].colore, c->disegni[i].colore) == 0) {
				++countColore;
			}
		}
		if (countColore == 1 || countForma == 1) {
			break;
		}
		++pos;
	} while (pos < c->n);

	return c->disegni + pos;
}