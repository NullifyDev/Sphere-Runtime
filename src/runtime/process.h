#ifndef PROCESS
#define PROCESS

#include <stdbool.h>
#include <stdlib.h>

#include "../sbf/parser/common.h"

#include "process/mem.h"
#include "process/fmem.h"
#include "process/vmem.h"

#include "./threads.h"

typedef struct Process
{
		unsigned int pid, thread_count, threads_active;

		char   *name;
		Mem     mem;
		FMem    fmem;
		VMem    vmem;
		Thread *threads;
} Process;

Process  *process_new (char *name, int size, int fmem_capacity,
	 int vmem_capacity, int threads_allocated);

#endif