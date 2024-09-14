#if !defined RAPPORTI_H
#define RAPPORTI_H

#include <stdint.h> // Necessario per il tipo uint16_t
#include <stdio.h>
#include <stdlib.h>

struct rapporto {
    uint16_t id;
    char tipo;
    float valore;
};

extern struct rapporto* leggi_rapporti(const char* filename, uint16_t* n);

#endif /* RAPPORTI_H */