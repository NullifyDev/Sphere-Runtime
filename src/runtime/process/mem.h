#ifndef MEM
#define MEM

#include <stdlib.h>

typedef struct Mem {
    char *loc;
    unsigned int capacity, count;
} Mem;

Mem mem_new(int size);
int mem_queryavailable(Mem *mem, int length);

#endif
