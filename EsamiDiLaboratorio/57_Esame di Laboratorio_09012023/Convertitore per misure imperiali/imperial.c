#define _CRT_SECURE_NO_WARNINGS
#include "imperial.h"

double conv_pollici(double n) {
	return n * 0.0254;
}

double conv_iarda(double n) {
	return 3 * (12 * n) * 0.0254;
}

double conv_miglio(double n) {
	return n * 1760 * 3 * 12 * 0.0254;
}

double conv_piedi(double n) {
	return n * 12 * 0.0254;
}

double to_meter(const char* imperial_length)
{
	if (imperial_length == NULL) {
		return -1;
	}
	double ris = 0;
	double num_letto;
	size_t len = strlen(imperial_length);
	size_t count = 0;
	while (count < len) {
		char misura[7] = { 0 };
		int n;
		sscanf(imperial_length, "%lf%n", &num_letto, &n);
		imperial_length += n;
		count += n;
		sscanf(imperial_length, " %[^ ]%n", misura, &n);
		imperial_length += n;
		count += n;
		if (strcmp(misura, "inch") == 0 || strcmp(misura, "inches") == 0 || strcmp(misura, "in") == 0
			|| strcmp(misura, "in.") == 0 || strcmp(misura, "\"") == 0) {
			ris += conv_pollici(num_letto);
		}
		else if (strcmp(misura, "foot") == 0 || strcmp(misura, "feet") == 0 || strcmp(misura, "ft") == 0
			|| strcmp(misura, "ft.") == 0 || strcmp(misura, "'") == 0) {
			ris += conv_piedi(num_letto);
		}
		else if (strcmp(misura, "yard") == 0 || strcmp(misura, "yards") == 0 || strcmp(misura, "yd") == 0
			|| strcmp(misura, "yd.") == 0) {
			ris+=conv_iarda(num_letto);
		}
		else {
			ris+=conv_miglio(num_letto);
		}
	}
	return ris;
}