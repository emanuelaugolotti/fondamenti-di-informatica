#define _CRT_SECURE_NO_WARNINGS
#include "nonogram.h"

bool nonogram_load(struct nonogram* ng, const char* filename)
{
	if (filename == NULL || ng == NULL) {
		return false;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return false;
	}
	if (feof(f)) {
		return false;
	}
	size_t nrows, ncols;
	fscanf(f, "%zu%*[\n]", &nrows);
	ng->n = nrows;
	ncols = nrows;
	ng->schema = malloc(nrows * ncols);
	for (size_t r = 0; r < nrows; ++r) {
		int letto;
		for (size_t c = 0; c < ncols; ++c) {
			letto = fgetc(f);
			ng->schema[r * ng->n + c] = letto;
		}
		letto = fgetc(f);
	}
	fclose(f);
	return true;
}