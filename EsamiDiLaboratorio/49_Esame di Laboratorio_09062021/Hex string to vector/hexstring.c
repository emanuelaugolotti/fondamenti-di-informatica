#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <string.h>

void hexstring2vec(const char* s, uint8_t out[8])
{
	char buffer[3] = "0";
	int conta = 0;  //conta il numero di coppie di cifre esadecimali
	for (int i = 0; s[i] != 0; i += 2) {
		strncpy(buffer, s + i, 2);
		uint8_t n = (uint8_t)strtol(buffer, NULL, 16);
		out[conta] = n;
		++conta;
	}
	if (conta < 8) {
		for (int i = conta; i < 8; ++i) {
			out[i] = 0x0;
		}
	}
	return;
}