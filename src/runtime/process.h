#ifndef PROCESS
#define PROCESS

#include <stdbool.h>
#include <stdlib.h>

#include "../sbf/parser/common.h"

#include "process/mem.h"
#include "process/fmem.h"
#include "process/vmem.h"

#include "./threads.h"
#include "./task.h"


typedef struct Process
{
		unsigned int pid, thread_count, threads_active;
		char    *name;
		Mem     *mem;
		FMem    *fmem;
		VMem    *vmem;
		BMem    *bmem;
		Thread **threads;
} Process;

Process *process_new (char *name, unsigned int mem_capacity, unsigned int fmem_capacity,
	unsigned int vmem_capacity, unsigned int bmem_capacity, unsigned int threads_allocated);

void process_exit(Process *proc);


#endif
