#define _CRT_SECURE_NO_WARNINGS
#include "scacchiera.h"

void stampa_scacchiera(const struct scacchiera* sc)
{
	if (sc == NULL) {
		return;
	}

	/*printf("+---+---+---+---+---+---+---+---+\n");
	for (int c = 7; c >= 0 ; --c) {
		printf("|");
		for (int r = 7; r >= 0; --r) {
			printf(" %c |", sc->caselle[r * 8 + c]);
		}
		printf("\n+---+---+---+---+---+---+---+---+\n");
	}*/

	printf("+---+---+---+---+---+---+---+---+\n");
	for (int r = 0; r < 8; ++r) {
		printf("|");
		for (int c = 0; c < 8; ++c) {
			printf(" %c |", sc->caselle[(7 - c) * 8 + 7 - r]);
		}
		printf("\n+---+---+---+---+---+---+---+---+\n");
	}
	
	return;
}