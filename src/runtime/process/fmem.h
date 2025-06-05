#ifndef FMEM
#define FMEM

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../../sbf/parser/objects/function.h"

typedef struct FMem {
    Function *loc;
    unsigned int capacity, count;
} FMem;

FMem *fmem_new(unsigned int capacity);
bool fmem_hasId(FMem *fmem, unsigned int id);
Function *fmem_getById (FMem *fmem, unsigned int id);
void _fmem_free(FMem *mem);

void E_fmem_defragment(FMem *fmem);

#endif
