#if !defined ANGOLI_H
#define ANGOLI_H

#include <stdint.h>
#include <stdlib.h>

struct angolo {
    uint16_t gradi;
    uint8_t primi;
    uint8_t secondi;
};

extern struct angolo differenza_angoli(struct angolo a, struct angolo b);

#endif /* ANGOLI_H */