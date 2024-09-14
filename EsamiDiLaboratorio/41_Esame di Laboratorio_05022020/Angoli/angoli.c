#include "angoli.h"

struct angolo somma_angoli(struct angolo a, struct angolo b)
{
	struct angolo somma;
	uint32_t sommaprimi = 0, sommasecondi;
	uint32_t sommagradi = 0;

	sommasecondi = a.secondi + b.secondi;
	if (sommasecondi >= 60) {
		while (sommasecondi >= 60) {
			sommaprimi += sommasecondi / 60;
			sommasecondi = sommasecondi % 60;
		}
	}
	sommaprimi += a.primi + b.primi;
	if (sommaprimi >= 60) {
		while (sommaprimi >= 60) {
			sommagradi += sommaprimi / 60;
			sommaprimi = sommaprimi % 60;
		}
	}
	sommagradi += a.gradi + b.gradi;
	
	somma.secondi = (uint8_t)sommasecondi;
	somma.primi = (uint8_t)sommaprimi;
	somma.gradi = (uint16_t)sommagradi;
	
	return somma;
}