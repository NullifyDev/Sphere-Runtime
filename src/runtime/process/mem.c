#include "mem.h"

Mem mem_new(int capacity) {
	Mem vmem;
	
	vmem.loc = (void *)calloc(sizeof(char), capacity);
	vmem.capacity = capacity;
	vmem.count = 0;

	return vmem;
}

int mem_queryavailable(Mem *mem, int length)
{
	int memlen = mem->capacity;

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
