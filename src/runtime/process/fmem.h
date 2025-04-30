#ifndef FMEM
#define FMEM

#include <stdlib.h>
#include <stdbool.h>
#include "../../sbf/parser/objects/function.h"

typedef struct FMem {
    Function *loc;
    unsigned int capacity, count;
} FMem;

FMem fmem_new(int size);
bool fmem_hasId(FMem *fmem, int id);
Function *fmem_getById (FMem *fmem, int id);

#endif
