#define _CRT_SECURE_NO_WARNINGS
#include "rle.h"

bool easy_rle_decode(const char* nomefilein, const char* nomefileout)
{
	if (nomefilein == NULL || nomefileout == NULL) {
		return false;
	}
	FILE* fin = fopen(nomefilein, "rb");
	FILE* fout = fopen(nomefileout, "wb");
	if (fin == NULL && fout == NULL) {
		return false;
	}
	if (fout != NULL && fin == NULL) {
		fclose(fout);
		return false;
	}
	if (fin != NULL && fout == NULL) {
		fclose(fin);
		return false;
	}
	while (1) {
		unsigned char numero;
		unsigned char scrivi;
		size_t ris1 = fread(&numero, 1, 1, fin);
		size_t ris2 = fread(&scrivi, 1, 1, fin);
		if (ris1 != 1 || ris2 != 1) {
			break;
		}
		size_t n = numero;
		++n;
		for (size_t i = 0; i < n; ++i) {
			fwrite(&scrivi, 1, 1, fout);
		}
	}
	fclose(fin);
	fclose(fout);
	return true;
}