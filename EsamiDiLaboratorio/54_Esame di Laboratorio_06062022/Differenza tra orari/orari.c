#include "orari.h"

struct orario differenza_orari(struct orario a, struct orario b)
{
	struct orario ora_out;

	if (a.ore < b.ore || (a.ore == b.ore && a.minuti < b.minuti) || 
		(a.ore == b.ore && a.minuti == b.minuti && a.secondi < b.secondi)) {
		ora_out.ore = 0xFF;
		ora_out.minuti = 0xFF;
		ora_out.secondi = 0xFF;
		return ora_out;
	}
	if (a.secondi < b.secondi) {
		a.secondi += 60;
		a.minuti -= 1;
	}
	ora_out.secondi = a.secondi - b.secondi;
	if (a.minuti < b.minuti) {
		a.minuti += 60;
		a.ore -= 1;
	}
	ora_out.minuti = a.minuti - b.minuti;
	ora_out.ore = a.ore - b.ore;
	
	return ora_out;
}