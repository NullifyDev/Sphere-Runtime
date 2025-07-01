#include "process.h"

Process *process_new (char *name, unsigned int mem_capacity, unsigned int fmem_capacity,
	unsigned int vmem_capacity, unsigned int bmem_capacity, unsigned int threads_allocated)
{
	Process *proc = calloc(1, sizeof(Process));

	proc->name = name;

	proc->mem  =  mem_new( mem_capacity);
	proc->fmem = fmem_new(fmem_capacity);
	proc->vmem = vmem_new(vmem_capacity);
	proc->bmem = bmem_new(bmem_capacity);

	proc->threads        = calloc (sizeof(Thread*), threads_allocated);
	proc->thread_count   = threads_allocated;
	proc->threads_active = 0;


	unsigned int i = 0;
	while (i < proc->thread_count) {
		proc->threads[i++] = thread_new(proc->mem, proc->fmem, proc->vmem, proc->bmem);
	}
	return proc;
}


void process_exit(Process *proc) {
	_fmem_free(proc->fmem);
	_vmem_free(proc->vmem);
	_mem_free(proc->mem);

	while (--proc->thread_count >= 1)
		_thread_free(proc->threads[proc->thread_count]);

	_thread_free(proc->threads[0]);
	
	proc->thread_count = 0;
	proc->threads_active = 0;

	proc->pid = 0;
	proc->name = NULL;
}
