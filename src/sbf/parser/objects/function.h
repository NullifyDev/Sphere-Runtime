#ifndef FUNCTION
#define FUNCTION

#include <stdlib.h>

#include "../block.h"
#include "../datatype/value.h"
// #include "../../../runtime/threads.h"

typedef struct Function
{
    unsigned int id,
                 blockId;
    Value *returnAddr; // address in the data memory (return address are reserved first thing before any operations)
} Function;

// Function *func_new(Thread *t, unsigned int id, Block *block);
#endif
