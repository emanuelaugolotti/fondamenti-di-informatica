#define _CRT_SECURE_NO_WARNINGS
#include "dataset.h"

struct dataset *dataset_load(const char *filename)
{
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return NULL;
	}
	struct dataset *d = malloc(sizeof(struct dataset));
	d->data = NULL;
	d->nrows = 0;
	
	while (1) { //Ciclo di lettura
		char fname[256];
		char prognosis[7];
		
		int res = fscanf(f, "%255[^,],%6s\n", fname, prognosis);
		/*int ris = fscanf(f, "%255[^,]", fname);
		ris = fscanf(f, ",%6[^\n]", prognosis);*/
		if (res != 2) {
			break;
		}
		
		struct row tmp;  //struct row temporanea
		tmp.prognosis = prognosis[0];
		tmp.filename = malloc(strlen(fname) + 1);
		strcpy(tmp.filename, fname);
		/*char *filenameTmp = malloc(strlen(fname) + 1);
		strcpy(filenameTmp, fname);
		struct row tmp = { filenameTmp, prognosis[0] };*/
		
		d->data = realloc(d->data, (d->nrows + 1) * sizeof(struct row));
		d->data[d->nrows] = tmp;
	    //*(d->data + d->nrows) = tmp;
		d->nrows += 1;
	}

	fclose(f);
	return d;
}
