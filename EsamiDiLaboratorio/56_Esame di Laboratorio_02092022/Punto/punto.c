#include "punto.h"

struct punto_pol cartesiano2polare(const struct punto_cart* p)
{
	struct punto_pol outpolari;
	double quadrato = p->x * p->x + p->y * p->y;
	outpolari.r = sqrt(quadrato);
	outpolari.t = atan2(p->y, p->x);
	
	return outpolari;
}


struct punto_cart polare2cartesiano(const struct punto_pol* p)
{
	struct punto_cart outcart;
	outcart.x = p->r * cos(p->t);
	outcart.y = p->r * sin(p->t);

	return outcart;
}