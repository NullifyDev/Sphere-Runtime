#ifndef VMEM
#define VMEM

#include <stdlib.h> 
#include <stdbool.h>

#include "../../sbf/parser/objects/variable.h"

typedef struct VMem {
    Variable *loc;
    unsigned int capacity, count;
} VMem;

VMem vmem_new(int size);

Variable *vmem_getById      (VMem **proc, int id );
bool      vmem_hasId        (VMem *proc, int id );
bool      _vmem_occupiedAddr(VMem *proc, int loc);
bool      _vmem_isEmpty     (Variable *var);

#endif
