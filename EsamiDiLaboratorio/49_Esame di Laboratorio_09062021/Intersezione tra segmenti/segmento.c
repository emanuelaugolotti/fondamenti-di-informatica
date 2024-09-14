#include "segmento.h"

struct segmento* intersezione(struct segmento s1, struct segmento s2)
{
	if (s1.a >= s1.b || s2.a >= s2.b) {
		return NULL;  //segmento non valido
	}
	//Qualora non esista intersezione tra i due segmenti, la funzione restituisce NULL.
	
	struct segmento* out = malloc(sizeof(struct segmento));
	int maxlim, minlim;
	minlim = s1.a < s2.a ? s2.a : s1.a;
	maxlim = s1.b > s2.b ? s2.b : s1.b;
	out->a = minlim;
	out->b = maxlim;
	if (minlim >= s1.a && minlim >= s2.a && maxlim <= s1.b && maxlim <= s2.b && out->a < out->b) {
		return out;
	} else {
		free(out);
		return NULL; //non esiste intersezione tra i due segmenti
	}
}