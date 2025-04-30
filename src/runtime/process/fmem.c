#include "fmem.h"

FMem fmem_new(int capacity) {
	FMem fmem;
	
	fmem.loc = calloc (capacity, sizeof(Function));
	fmem.capacity = capacity;
	fmem.count = 0;

	return fmem;
}

bool fmem_hasId(FMem *fmem, int id)
{
	if (fmem->count == 0) { return false; }

	int i = 0;
	while (i < fmem->count) {
		if (&(fmem->loc[i]) == NULL) { continue; }
		if (fmem->loc[i++].id != id) { continue; }
		return true;
	}
	return false;
}

Function *fmem_getById (FMem *fmem, int id)
{
	if (fmem->count == 0) { return NULL; }

	int i = 0;
	while (i < fmem->count) {
		if (&(fmem->loc[i]) == NULL) { continue; }
		if (fmem->loc[i].id != id) { continue; }
		return &fmem->loc[i];
	}
	
	return NULL;
}