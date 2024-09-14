#if !defined PUNTI_INCERCHIO_H
#define PUNTI_INCERCHIO_H

#include <stdlib.h>

struct punto {
    double x, y;
};

extern struct punto* punti_in_cerchio(const struct punto* p, size_t n, double r, size_t* count);

#endif /* PUNTI_INCERCHIO_H */