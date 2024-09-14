#include "getline.h"

size_t getline(char** lineptr, size_t* n, FILE* stream)
{
	size_t count = 0; //numero caratteri letti
	
	//se lineptr punta ad un un puntatore NULL o se la dimensione del buffer è inferiore a 16, la funzione 
	//rialloca un buffer da 16 byte
	if (*lineptr == NULL || *n < 16) {
		*lineptr = realloc(*lineptr, 16);
		*n = 16;
	}

	char* p = *lineptr;
	size_t pos = 0;  //posizione nel buffer
	size_t capacity = *n; //lascio lo spazio per il terminatore

	while (1) {
		//leggo fino al primo a capo che incontro
		int c = fgetc(stream);
		if (c == EOF)
		{
			return 0;
		}
		++count; //Aumento di 1 il numero di caratteri letti
	
		//Nel caso si raggiunga la capacità massima, la funzione rialloca il buffer raddoppiandone la capacità 
	//e aggiorna sia il puntatore puntato da lineptr, sia la capacità massima puntata da n.
		if (count > capacity - 1) {
			p = realloc(p, 2 * capacity);
			*lineptr = p;
			capacity *= 2;
		}
		
		p[pos] = c;
		++pos;
		
		if (c == '\n') { //passo alla riga successiva
			p[pos] = 0;  //metto il terminatore a fine riga
			break;
		}
	}
	*n = capacity;
	return count; //restituisce il numero di caratteri letti
}