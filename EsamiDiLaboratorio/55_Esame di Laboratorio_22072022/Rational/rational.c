#define _CRT_SECURE_NO_WARNINGS
#include "rational.h"

struct rational* rational_read(const char* filename, size_t* size)
{
	size_t lette = 0; //numero frazioni lette
	//fare una nuova variabile in cui mettere il numero delle frazioni lette e poi metterlo in *size
	
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		*size = lette;
		return NULL;
	}
	
	struct rational* out = NULL;
	while (1) {
		int numTmp;
		unsigned int denTmp;
		int ris = fscanf(f,"%d /%u", &numTmp, &denTmp);
		if (ris != 2) {
			break;
		}
		out = realloc(out, (lette + 1) * sizeof(struct rational));  //Aumento di 1 il vettore di struct puntato da out
		out[lette].num = numTmp;
		out[lette].den = denTmp;
		++lette;
    }
	*size = lette;
	fclose(f);
	return out;
}