#include <math.h>

double area_trapezio(double a, double b, double c, double d)
{
	double condizione = 1. / 4 * pow((b - a + (c * c - d * d) / (b - a)), 2);
	//se divido un int per un double, l'int viene promosso a double. 1 / 2 = 0 perchè, per il compilatore,
	// 1 è un int, 2 è un int e quindi fa la divisione intera
	if (pow(c, 2) < condizione) {
		return 0.;
	}
	double area = (a + b) * sqrt(c * c - condizione) / 2;
	
	return area;
}