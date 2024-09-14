#define _CRT_SECURE_NO_WARNINGS
#include "binary.h"

void stampa_binario(const char* filename_in, const char* filename_out)
{
	FILE *f1 = fopen(filename_in, "rb");
	if (f1 == NULL) {
		return;
	}

	FILE* f2 = fopen(filename_out, "w");

	unsigned char letto; //byte letto
	size_t count = 0;
	while (1) {
			size_t ris = fread(&letto, 1, 1, f1);
			if (ris != 1) {
				break;
			}
			//converto il byte letto in binario
			unsigned char buffer[9] = { '0', '0', '0', '0', '0', '0', '0', '0'};
			for (size_t i = 0; letto != 0; ++i) {
				if (letto % 2 == 1) {
					buffer[7 - i] = '1';
				}
				letto /= 2;
			}
			fprintf(f2, "%s", buffer); //sctivo il byte letto
			++count;
			if (count % 8 == 0) {  //Ogni 8 byte scritti metto un a capo
				fprintf(f2, " \n");
			} else {
				fprintf(f2, " ");
			}
	}

	fclose(f1);
	fclose(f2);
	return;
}