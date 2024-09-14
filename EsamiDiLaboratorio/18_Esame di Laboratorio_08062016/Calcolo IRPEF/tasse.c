#include <stdlib.h>

unsigned int irpef(unsigned int stipendio, unsigned int* scaglioni, unsigned int* aliquote, size_t n)
{
	size_t pos;
	unsigned int tasse = 0;
	for (size_t i = 1; i <= n; ++i) {
		if (stipendio <= scaglioni[i]) {
			pos = i;
			break;
		}
	}
	if (stipendio > scaglioni[n - 1]) {
		pos = n - 1;
	}
	for (size_t i = 1; i < pos; ++i) {
		tasse = tasse + (scaglioni[i] - scaglioni[i - 1]) * aliquote[i - 1] / 100;
	}
	if (pos < n - 1) {
		tasse = tasse + (stipendio - scaglioni[pos - 1]) * aliquote[pos - 1] / 100;
	}
	else {
		tasse = tasse + (scaglioni[pos] - scaglioni[pos - 1]) * aliquote[pos - 1] / 100 +
			(stipendio - scaglioni[pos]) * aliquote[pos] / 100;
	}
	return tasse;
}