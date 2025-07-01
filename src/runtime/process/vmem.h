#ifndef VMEM
#define VMEM

#include <string.h>
#include <stdlib.h> 
#include <stdbool.h>

#include "../../sbf/parser/objects/variable.h"

typedef struct VMem {
    Variable *loc;
    unsigned int capacity, count;
} VMem;

VMem *vmem_new(const unsigned int capacity);

Variable *vmem_getById     (VMem *proc, const unsigned int id);
bool      vmem_hasId       (VMem *proc, const unsigned int id );
bool     _vmem_occupiedAddr(VMem *proc, const unsigned int loc);
bool     _vmem_isEmpty     (Variable *var);
void     _vmem_free        (VMem *mem);

#endif
