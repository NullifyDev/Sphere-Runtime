#ifndef THREADS
#define THREADS

#include <stdlib.h>
#include <stdbool.h>

#include "../sbf/parser/common.h"
#include "../sbf/parser/block.h"

#include "process/mem.h"
#include "process/fmem.h"
#include "process/vmem.h"

typedef struct Task {
    unsigned int length;
    char *content;
    unsigned int iter;
} Task;

typedef struct Thread
{
     Mem  *mem;
    FMem *fmem;
    VMem *vmem;

    Task task; // localized version of instructions (read from either file or memory)

    bool isActive;
} Thread;

Thread thread_new(unsigned int id, Mem *mem, FMem *fmem, VMem *vmem);
void thread_loadTask(Thread *t, char *sbe);

#endif