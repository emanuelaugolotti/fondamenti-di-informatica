#define _CRT_SECURE_NO_WARNINGS
#include "frequenza.h"

struct oggetto* piu_frequente(const struct carta* c)
{
	struct oggetto* out = malloc(sizeof(struct oggetto));  //Alloco spazio per la struct oggetto nuova
	size_t piu_frequente = 0;
	size_t pos_frequente_next;

	for (size_t pos = 0; pos < c->n; ++pos) {
		//Considero la struct oggetto di posizione pos
		size_t freq_corrente = 0;
		for (size_t i = 0; i < c->n; ++i) { //Calcolo la frequenza della struct oggetto considerata
			if (strcmp(c->disegni[pos].forma, c->disegni[i].forma) == 0 &&
				strcmp(c->disegni[pos].colorenumero, c->disegni[i].colorenumero) == 0) {
				++freq_corrente;
			}
		}
		if (freq_corrente > piu_frequente) {
			piu_frequente = freq_corrente;
			pos_frequente_next = pos;
		}
	}

	out->forma = malloc(1 + strlen(c->disegni[pos_frequente_next].forma));
	out->colorenumero = malloc(1 + strlen(c->disegni[pos_frequente_next].colorenumero));

	strcpy(out->forma, c->disegni[pos_frequente_next].forma);
	strcpy(out->colorenumero, c->disegni[pos_frequente_next].colorenumero);

	return out;
}