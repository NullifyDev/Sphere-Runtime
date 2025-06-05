#include "mem.h"

Mem *mem_new(unsigned int capacity) {
	Mem *vmem = calloc(1, sizeof(Mem));
	
	vmem->loc = (void *)calloc(capacity, sizeof(char));
	vmem->capacity = capacity;
	vmem->count = 0;

	return vmem;
}

int mem_queryavailable(Mem *mem, unsigned int length)
{
	unsigned int memlen = mem->capacity;

	if (memlen == 0) { return 0; }
	if (length >= memlen) { return 0; }

	unsigned int i = 0, j = 0;
	while (i < memlen) {
		if (i + length >= memlen) { return 0; }
		// if (mem->loc[i] != 0)  { break; }

		while (j < memlen - i - 1) {
			if (j >= length) { return i; }
			if (mem->loc[i + j] != 0) { break; }

			j++;
		}
		i++;
	}
	return 0;
}

void _mem_free(Mem *mem) {
	mem->count = 0;
	mem->capacity = 0;
 	memset(mem->loc, 0, mem->capacity);
	free(mem->loc); 
}