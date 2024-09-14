#if !defined READ_DVEC_C
#define READ_DVEC_C

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct dvec {
    size_t n;
    double* d;
};

extern struct dvec* read_dvec_comp(const char* filename);

#endif /* READ_DVEC_C */