#include <math.h>

double newton(double m1, double m2, double d)
{
	//Se m1 non è positivo, oppure se m2 non è positivo, oppure se d non è positivo, la funzione restituisce -1.
	if (m1 <= 0 || m2 <= 0 || d <= 0) {
		return -1;
	}

	double cost_gravitazione = 6.67259 * pow(10.0, -11.0);
	double forza = cost_gravitazione * m1 * m2 / pow(d, 2);

	return forza;
}