#if !defined READ_DVEC_H
#define READ_DVEC_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct dvec {
    size_t n;
    double* d;
};

struct dvec* read_dvec_comp(const char* filename);

#endif /* READ_DVEC_H */
