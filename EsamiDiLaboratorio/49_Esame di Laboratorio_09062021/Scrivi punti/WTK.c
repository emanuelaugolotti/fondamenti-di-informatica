#define _CRT_SECURE_NO_WARNINGS
#include "WTK.h"

size_t write_points(FILE* f, const struct point* p, size_t n)
{
	//La funzione restituisce il numero di elementi correttamente salvati su file.
	//Se, per qualsivoglia motivo, la funzione non scrive nessun elemento sul file, essa quindi restituisce 0.
	if (n == 0 || p == NULL) {
		return 0;
	}

	double x, y;
	size_t count = 0;
	for (size_t i = 0; i < n; ++i) {  //scorro tutti gli elementi del vettore
		x = p[i].x;
		y = p[i].y;
		fprintf(f, "POINT(%g %g)\n", x, y);
		++count;
	}
	
	return count;
}