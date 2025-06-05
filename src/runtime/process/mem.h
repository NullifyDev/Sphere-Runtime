#ifndef MEM
#define MEM

#include <stdlib.h>
#include <string.h>

typedef struct Mem {
    char *loc;
    unsigned int capacity, count;
} Mem;

Mem *mem_new(unsigned int capacity);
int mem_queryavailable(Mem *mem, unsigned int length);
void _mem_free(Mem *mem);

#endif
