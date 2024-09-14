#if !defined GETLINE_H
#define GETLINE_H

#include <stdio.h>
#include <stdlib.h>

extern size_t getline(char** lineptr, size_t* n, FILE* stream);

#endif  /* GETLINE_H */