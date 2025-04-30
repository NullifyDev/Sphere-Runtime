#include "./threads.h"

void thread_clearTask(Thread *t)
{
    t->task.content = NULL;
    t->task.length  = 0;
    t->task.iter    = 0;
}

Thread thread_new(unsigned int id, Mem *mem, FMem *fmem, VMem *vmem)
{
    Thread t;

    t.mem  = mem;
    t.fmem = fmem;
    t.vmem = vmem;

    t.isActive = true;

    thread_clearTask(&t);

    return t;
}

void thread_loadTask(Thread *t, char *sbe)
{
    t->task.content = sbe;
    t->task.length  = sizeof(sbe);
    t->task.iter    = 0;
}