#include "fmem.h"

FMem *fmem_new(unsigned int capacity) 
{
	FMem *fmem = calloc(1, sizeof(FMem));
	
	fmem->loc = calloc (capacity, sizeof(Function));
	fmem->capacity = capacity;
	fmem->count = 0;

	return fmem;
}

bool fmem_hasId(FMem *fmem, unsigned int id)
{
	if (fmem->count == 0) { return false; }

	unsigned int i = 0;
	while (i < fmem->count) {
		if (&(fmem->loc[i]) == NULL) { continue; }
		if (fmem->loc[i++].id != id) { continue; }
		return true;
	}
	return false;
}

Function *fmem_getById (FMem *fmem, unsigned int id)
{
	if (fmem->count == 0) { return NULL; }

	unsigned int i = 0;
	while (i < fmem->count) {
		if (&fmem->loc[i] == NULL) { continue; }
		if (fmem->loc[i].id != id) { continue; }
		return &fmem->loc[i];
	}
	
	return NULL;
}

void E_fmem_defragment(FMem *fmem) {
	unsigned int i = 0, j = 0;
	while (i < fmem->capacity) 
	{
		if (&fmem->loc[i] == NULL) {
			j = i;
			while (++j < fmem->capacity) {
				if (&fmem->loc[j] == NULL) continue;
				fmem->loc[i++] = fmem->loc[j];
			}
				
			while (i < fmem->capacity)
				fmem->loc[i++] = (Function) {	
					.id = 0, 
					.contents = &(Block) { 
						0, 
						0, 
						0, 
						0
					},
					.returnAddr = &(Value){ 0, NULL, 0, 0 }
				};

			return;
		}
		i++;
	}
}

void _fmem_free(FMem *mem) {
	mem->count = 0;
	mem->capacity = 0;
 	memset(mem->loc, 0, mem->capacity);
	free(mem->loc); 
}