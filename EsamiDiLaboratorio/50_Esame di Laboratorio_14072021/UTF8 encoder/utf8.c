#include "utf8.h"

size_t utf8_encode(uint32_t codepoint, uint8_t seq[4])
{
	//La funzione ritorna il numero di byte prodotti in output, o 0 se il codice è maggiore di 10FFFF
	if (codepoint > 0x10FFFF) {
		return 0;
	}
	size_t count;
	memset(seq, 0, 4); //azzero tutti i byte di seq
	if (codepoint < 0x0080) {
		seq[0] = codepoint % 128;
		count = 1;
	}
	if (codepoint >= 0x0080 && codepoint < 0x0800) {
		seq[0] = (codepoint >> 6) + 0xC0;
		seq[1] = (codepoint % 64) + 0x80;
		count = 2;
	}
	if (codepoint > 0x0800 && codepoint < 0x10000) {
		seq[0] = (codepoint >> 12) + 0xE0;
		seq[1] = (codepoint / 64) % 64 + 0x80;
		seq[2] = (codepoint % 64) + 0x80;
		count = 3;
	}
	if (codepoint > 0x10000) {
		seq[0] = (codepoint >> 18) + 0xF0;
		seq[1] = (codepoint / (64 * 64)) % 64 + 0x80;
		seq[2] = (codepoint / 64) % 64 + 0x80;
		seq[3] = (codepoint % 64) + 0x80;
		count = 4;
	}

	return count;
}