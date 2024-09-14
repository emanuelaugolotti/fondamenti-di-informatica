#include "unico.h"

int main(void)
{
    struct carta c = {
        (struct oggetto[]) {
            { "missile", "verde" },
            { "bomba", "verde" },
            { "bomba", "rosso" },
            { "missile", "nero" },
            { "lampadina", "blu" },
            { "nota", "giallo" },
            { "cavallo", "rosso" },
            { "lampadina", "nero" },
            { "bomba", "blu" },
            { "cavallo", "giallo" },
        }, 10 };
    const struct oggetto* o = unico(&c);
    return 0;
}