#include <stdlib.h>
#include <string.h>

const void* memmem(const void* pagliaio, size_t psize, const void* ago, size_t asize)
{
	//se pagliaio è NULL, se psize è 0, se ago è NULL, o se asize è 0, la funzione restituisce NULL
	if (pagliaio == NULL || psize == 0 || asize == 0 || ago == NULL || asize > psize) {
		return NULL;
	}

	const char* ptrago = ago;
	const char* inizio = pagliaio;
	char* out = NULL;
	size_t count = 0;
	size_t tot_count = psize;
	
	while (1) {
		out = memchr(inizio, ptrago[0], tot_count);
		if (out == NULL) {
			break;
		}
		if (memcmp(out, ago, asize) == 0) {
			break;
		}
		count = out - inizio;
		if (tot_count == psize) {
			tot_count -= count;
		} else {
			tot_count -= (count + 1);
		}
		inizio = out + 1;
	}
	
	return out;
}