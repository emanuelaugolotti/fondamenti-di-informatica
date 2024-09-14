#if !defined STAMPA_SCACCHIERA
#define STAMPA_SCACCHIERA

#include <stdio.h>
#include <stdlib.h>

struct scacchiera {
    char caselle[64];
};

extern void stampa_scacchiera(const struct scacchiera* sc);

#endif /* STAMPA_SCACCHIERA */