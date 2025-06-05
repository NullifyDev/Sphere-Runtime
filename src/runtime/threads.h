#ifndef THREADS
#define THREADS

#include <stdlib.h>
#include <stdbool.h>

#include "../sbf/parser/common.h"
#include "../sbf/parser/block.h"

#include "misc/stack.h"
#include "task.h"

#include "process/mem.h"
#include "process/fmem.h"
#include "process/vmem.h"
#include "process/bmem.h"

typedef struct Thread
{
     Mem  *mem;
    FMem *fmem;
    VMem *vmem;
    BMem *bmem;
    
    Stack *task; // localized version of instructions (read from either file or memory)

    bool isActive;
} Thread;

Thread *thread_new(Mem *mem, FMem *fmem, VMem *vmem, BMem *bmem);
// void thread_loadTask(Thread *t, unsigned char *sbe, unsigned int length);
void thread_loadTask(Thread *t, unsigned char *sbe, unsigned int length);

void thread_clearTask(Thread *t);
void _thread_free(Thread *t);


#endif