#include "process.h"
#include "process/fmem.h"
#include "process/vmem.h"

Process *process_new (char *name, int mem_capacity, int fmem_capacity,
	int vmem_capacity, int threads_allocated)
{
	Process *proc = &(Process) {
		.name = name,

		.mem  =  mem_new( mem_capacity),
		.fmem = fmem_new(fmem_capacity),
		.vmem = vmem_new(vmem_capacity),

		.threads        = calloc (sizeof(Thread), threads_allocated),
		.thread_count   = threads_allocated,
		.threads_active = 0,
	};

	unsigned int i = 0;
	while (i < proc->thread_count) {
		proc->threads[i] = thread_new (i++, &proc->mem, &(proc->fmem), &(proc->vmem));
	}
	return proc;
}