#define _CRT_SECURE_NO_WARNINGS
#include "rectangle.h"

bool rect_load(FILE* f, struct rect* r) 
//La funzione ritorna true se riesce a leggere correttamente i 4 interi, false altrimenti.
{
	/* Altro metodo:
	size_t ris = fread(&(r->a.x), sizeof(int32_t), 1, f);
	if (ris != 1) {
		return false;
	}
	ris = fread(&(r->a.y), sizeof(int32_t), 1, f);
	if (ris != 1) {
		return false;
	}
	ris = fread(&(r->b.x), sizeof(int32_t), 1, f);
	if (ris != 1) {
		return false;
	}
	ris = fread(&(r->b.y), sizeof(int32_t), 1, f);
	if (ris != 1) {
		return false;
	}*/
	
	int32_t buffer[4];
	size_t ris = fread(buffer, sizeof(int32_t), 4, f);
	if (ris != 4) {
		return false;
	}
	r->a.x = buffer[0];
	r->a.y = buffer[1];
	r->b.x = buffer[2];
	r->b.y = buffer[3];

	return true;
}