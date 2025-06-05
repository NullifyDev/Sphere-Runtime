#include "./threads.h"

void thread_clearTask(Thread *t)
{
    stack_flush(t->task);
}

Thread *thread_new(Mem *mem, FMem *fmem, VMem *vmem, BMem *bmem)
{
    Thread *t = calloc(1, sizeof(Thread));

    t->mem  = mem;
    t->fmem = fmem;
    t->vmem = vmem;
    t->bmem = bmem;

    t->isActive = true;
    
    t->task = stack_new(255);

    return t;
}

void thread_loadTask(Thread *t, unsigned char *sbe, unsigned int length)
// void thread_loadTask(Thread *t, unsigned char *sbe, unsigned int length)
{
    Task *task = calloc(sizeof(Task), 1);
    task->content = sbe;
    task->length  = length;
    task->iter    = 0;

    stack_push(t->task, (void*)task);
}

void _thread_free(Thread *t) 
{
    _stack_free(t->task);
    free(t->fmem);
    free(t->vmem);
    free(t->mem);
    
    t->isActive = false;
}