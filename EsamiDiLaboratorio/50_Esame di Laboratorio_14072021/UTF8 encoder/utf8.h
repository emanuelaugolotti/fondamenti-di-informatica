#if !defined UTF_H
#define UTF_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

extern size_t utf8_encode(uint32_t codepoint, uint8_t seq[4]);

#endif /* UTF_H */