#if !defined PATH_SPLIT_H
#define PATH_SPLIT_H

#include <stdlib.h>
#include <string.h>

extern void path_split(const char* str, char** path, char** filename);

#endif /* PATH_SPLIT_H */