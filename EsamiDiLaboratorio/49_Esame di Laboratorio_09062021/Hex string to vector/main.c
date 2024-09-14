#include <stdint.h>
extern void hexstring2vec(const char* s, uint8_t out[8]);

int main(void) {
	
	char stringa[] = "35AF";
	uint8_t vecris[8];
	hexstring2vec(stringa, vecris);

	return 0;
}