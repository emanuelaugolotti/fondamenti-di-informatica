#include "angoli.h"

struct angolo differenza_angoli(struct angolo a, struct angolo b)
{
	struct angolo differenza;
	
	//Caso angolo a < angolo b
	if (a.gradi < b.gradi || (a.gradi==b.gradi && a.primi < b.primi) || 
		(a.gradi == b.gradi && a.primi == b.primi && a.secondi < b.secondi)) {
		differenza.gradi = -1;
		differenza.primi = -1;
		differenza.secondi = -1;
		return differenza;
	}
	
	//Caso angolo a > angolo b
	if (a.secondi < b.secondi) {
		a.primi -= 1;
		a.secondi += 60;
	}
	differenza.secondi = a.secondi - b.secondi;
	if (a.primi < b.primi) {
		a.gradi -= 1;
		a.primi += 60;
	}
	differenza.primi = a.primi - b.primi;
	differenza.gradi = a.gradi - b.gradi;

	return differenza;
}