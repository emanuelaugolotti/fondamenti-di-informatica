#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>

void scrivi_v(FILE* f, uint8_t n)
{
	if (n == 0) {
		return;
	}

	for (int riga = 0; riga < n; ++riga) { 
	//considero la riga n-esima
		
		//metto gli spazi
		for (int spazi = 0; spazi < riga; ++spazi) {  
			fprintf(f, " ");
		}
		
		fprintf(f,"\\");
		
		//metto gli spazi
		int count = 2 * n - 2;
		for (int spazi = 0; spazi < (count - 2 * riga); ++spazi) {
			fprintf(f, " ");
		}
		
		fprintf(f, "/\n");
	}
	return;
}