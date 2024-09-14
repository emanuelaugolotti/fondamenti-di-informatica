#if !defined RECTANGLE_H
#define RECTANGLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

struct point {
    int32_t x, y;
};

struct rect {
    struct point a, b;
};

extern bool rect_load(FILE* f, struct rect* r);

#endif /* RECTANGLE_H */