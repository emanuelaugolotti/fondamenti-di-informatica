#include <stdlib.h>

int cercaElemUtile(int* v, size_t pos, size_t n, int max)
{
	for (size_t i = pos; i < n; ++i) {
		if (v[i] <= max) {
			return i;
		}
	}
	return -1;  //nel vettore non c'è nessun elemento <= a max
}

size_t shorten(int* v, size_t n, int max)
{
	if (v == NULL) {
		return 0;
	}
	size_t pos_vuota = 0, new_pos = 0;
	size_t count = 0;
	for (size_t i = 0; i < n; ++i) {
		if (v[pos_vuota] > max || (v[pos_vuota] <= max && pos_vuota != i)) {
			if (cercaElemUtile(v, i, n, max) != -1) {
				new_pos = (size_t)cercaElemUtile(v, i, n, max);
			}
			else {
				return count;
			}
			v[pos_vuota] = v[new_pos];
			++pos_vuota;
			i = new_pos;
			++new_pos;
			++count;
		}
		else if (v[pos_vuota] <= max && pos_vuota == i) {
			i = pos_vuota;
			++pos_vuota;
			++count;
		}
	}
	return count;
}