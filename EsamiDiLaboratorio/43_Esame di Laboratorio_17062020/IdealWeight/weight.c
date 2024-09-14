#include "weight.h"

double ideal_weight(int h, int age, char sex, enum formula f)
{
	//Se h<0 o age<0, o il valore di sex non è uno tra F e M, o f ha un valore diverso da quelli ammissibili, 
	//la funzione restituisce -1
	if (h < 0 || age < 0 || (sex != 'M' && sex != 'F')) {
		return -1;
	}
	double ideal;
	switch (f) {
	case lorenz: {
		if (sex == 'M') {
			ideal = h - 100. - (h - 150.) / 4.0;
		}
		else {
			ideal = h - 100. - (h - 150.) / 2.0;
		}
		break;
	}
	case berthean: {
		ideal = 0.8 * (h - 100.) +  age / 2.0;
		break;
	}
	case keys: {
		if (sex == 'M') {
			ideal = 22.1 * pow(h / 100., 2);
			break;
		}
		else {
			ideal = 20.6 * pow(h / 100., 2);
			break;
		}
	}
	default: return - 1;
	}
	return ideal;
}