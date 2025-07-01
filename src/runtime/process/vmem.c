#include "vmem.h"


VMem *vmem_new(const unsigned int capacity) 
{
	VMem *vmem = calloc(1, sizeof(VMem));

	vmem->loc = calloc (capacity, sizeof(Variable));
	vmem->capacity = capacity;
	vmem->count = 0;

	return vmem;
}

bool _vmem_isEmpty(Variable *var) {
	return var->id == 0 && var->length == 0 && var->pos == 0 && var->type == 0;
}

bool _vmem_occupiedAddr(VMem *vmem, const unsigned int loc)
{
    if (vmem->count == 0) return NULL;

	unsigned int i = loc;
    while (i < vmem->count) {
		Variable *var = &vmem->loc[i];
		printf("var == NULL: %s | _vmem_isEmpty(var): %s", var == NULL ? "true" : "false", _vmem_isEmpty(var) ? "true" : "false");
		if (_vmem_isEmpty(var))
			return true;
	}
	return false;
}
 
bool vmem_hasId(VMem *vmem, const unsigned int id)
{
	if (vmem->count == 0) return false;

	unsigned int i = 0;
	while (i < vmem->count) {
		if (&(vmem->loc[i]) == NULL) { i++; continue; }
		if (vmem->loc[i++].id != id) continue;
		return true;
	}
	return false;
}

Variable *vmem_getById(VMem *vmem, const unsigned int id)
{
	VMem v = vmem[0]; 
    if (v.count == 0) { return NULL; }

	unsigned int i = 0;
    while (i < v.count) {
        if (&(v.loc[i]) == NULL) {
            i++;
            continue;
        }
        if (v.loc[i].id == id) { return &(v.loc[i]); }
        
        i++;
    }
	return NULL;
}

void _vmem_free(VMem *mem) {
	mem->count = 0;
	mem->capacity = 0;
 	memset(mem->loc, 0, mem->capacity);
	free(mem->loc); 
}