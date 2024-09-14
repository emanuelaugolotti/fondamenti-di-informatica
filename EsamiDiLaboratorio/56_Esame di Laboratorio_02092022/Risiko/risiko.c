#include "risiko.h"

void confronta_lanci(const struct lancio* attacco, const struct lancio* difesa,
    char* perse_attacco, char* perse_difesa)
{
    char nLanci = 3;  //numero lanci dadi
    if (attacco->n_dadi <= difesa->n_dadi) {
        nLanci = attacco->n_dadi;
    }
    if (difesa->n_dadi < attacco->n_dadi) {
        nLanci = difesa->n_dadi;
    }

    *perse_attacco = 0;
    *perse_difesa = 0;
    for (unsigned char pos = 0; pos < (unsigned char)nLanci; ++pos) {
        if (attacco->valori[pos] == difesa->valori[pos]) {
            ++(*perse_attacco);
        } else {
            attacco->valori[pos] > difesa->valori[pos] ? ++(*perse_difesa) : ++(*perse_attacco);
        }
    }

    return;
}