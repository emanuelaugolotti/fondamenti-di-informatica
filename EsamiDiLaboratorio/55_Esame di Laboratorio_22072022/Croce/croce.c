#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void stampa_croce(FILE* f, size_t dim)
{
	if (dim == 0) {
		return;
	}

	for (size_t i = 0; i < dim; ++i) {
		for (size_t spazi_est = i; spazi_est > 0; --spazi_est) {  //spazi esterni
			fprintf(f, " ");
		}
		fprintf(f, "\\");  //barretta
		for (size_t spazi_int = 0; spazi_int < dim * 2 - 2 - 2 * i; ++spazi_int) {  //spazi interni
			fprintf(f, " ");
		}
		fprintf(f, "/\n"); //barretta
	}
	for (size_t i = 0; i < dim; ++i) {
		for (size_t spazi_est = dim - 1 - i; spazi_est > 0; --spazi_est) {  //spazi esterni
			fprintf(f, " ");
		}
		fprintf(f, "/");  //barretta
		for (size_t spazi_int = 0; spazi_int < i * 2; ++spazi_int) {  //spazi interni
			fprintf(f, " ");
		}
		fprintf(f, "\\\n"); //barretta
	}
	return;
}
