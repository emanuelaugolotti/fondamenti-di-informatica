#include "punti_in_cerchio.h"

struct punto* punti_in_cerchio(const struct punto* p, size_t n, double r, size_t* count)
{
	//Se p=NULL, oppure se n=0, oppure se r non è positivo, oppure se nessun punto è all'interno del cerchio, 
	//la funzione restituisce NULL e imposta il valore puntato da count a 0.
	if (p == NULL || r <= 0) {
		*count = 0;
		return NULL;
	}

	size_t conta = 0; //numero punti dentro al cerchio
	struct punto* out = NULL;
	for (size_t i = 0; i < n; ++i) { //scorro tutti gli elementi del vettore di struct punto p
		double d2 = (p[i].x) * (p[i].x) + (p[i].y) * (p[i].y);  //distanza dall'origin al quadrato
		if (d2 < (r * r)) {
			out = realloc(out, (conta + 1) * sizeof(struct punto));
			out[conta].x = p[i].x;
			out[conta].y = p[i].y;
			++conta;
		}
	}
	if (conta == 0) {
		*count = 0;
		return NULL;
	}
	*count = conta;
	return out;
}