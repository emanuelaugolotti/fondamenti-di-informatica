#if !defined WTK_H
#define WTK_H

#include <stdlib.h>
#include <stdio.h>

struct point {
    double x, y;
};

extern size_t write_points(FILE* f, const struct point* p, size_t n);

#endif /* WTK_H */