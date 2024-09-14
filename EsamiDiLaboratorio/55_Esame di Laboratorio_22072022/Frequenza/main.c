#include "frequenza.h"

int main(void)
{
    const struct carta c = {
        (struct oggetto[]) {
            { "pesce", "blu" },
            { "papera", "rossa" },
            { "pesce", "blu" },
            { "papera", "rossa" },
            { "coniglio", "giallo" },
            { "papera", "rossa" },
            { "coniglio", "giallo" },
            { "coniglio", "giallo" },
            { "pesce", "blu" },
            { "papera", "rossa" },
            { "coniglio", "giallo" },
            { "papera", "rossa" },
            { "gorilla", "nero" },
            { "gorilla", "nero" },
            { "papera", "rossa" },
        }, 15 };
    struct oggetto* ogg = piu_frequente(&c);
    free(ogg->forma);
    free(ogg->colorenumero);
    free(ogg);
    return 0;
}