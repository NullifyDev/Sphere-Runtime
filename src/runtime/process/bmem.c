#include "bmem.h"


BMem *bmem_new(const unsigned int capacity) 
{
	BMem *bmem = calloc(1, sizeof(BMem));

	bmem->loc = calloc(capacity+1, sizeof(Block));
	bmem->capacity = capacity;
	bmem->count = 1;

	return bmem;
}

Block *bmem_add(BMem *bmem, Block *blk) 
{
    if (_bmem_firstUnused(bmem) == NULL) 
    {
        printf("bmem is full - aborting\n");
        exit(1);
		return NULL; 
    }

	Block *b = _bmem_firstUnused(bmem);
	*b = *blk;
	return b;
}

bool _bmem_isEmpty(Block *blk) {
	return blk->id == 0 && blk->length == 0 && blk->count == 0 && blk->instructions == NULL;
}

Block *_bmem_firstUnused(BMem *bmem) 
{
    unsigned int i = 1;
    while (i < bmem->capacity) 
    {
        Block *blk = &bmem->loc[i];
        if (blk->length == 0 && blk->count == 0 && blk->instructions == 0) return blk;
        i++;
    }
    return NULL;
}

bool _bmem_isFull(BMem *bmem) {
    return bmem->count == bmem->capacity;
}

bool _bmem_freeAddr(BMem *bmem, const unsigned int loc)
{
    if (bmem->count == 0) return NULL;

	unsigned int i = loc;
    while (i < bmem->count) {
		Block *blk = &bmem->loc[i];
		printf("blk == NULL: %s | _bmem_isEmpty(blk): %s", blk == NULL ? "true" : "false", _bmem_isEmpty(blk) ? "true" : "false");
		if (_bmem_isEmpty(blk)) return true;
	}
	return false;
}
 
bool bmem_hasId(BMem *bmem, const unsigned int id)
{
	if (bmem->count == 0) { return false; }

	unsigned int i = 0;
	while (i < bmem->count) {
		if (&(bmem->loc[i]) == NULL) { i++; continue; }
		if (bmem->loc[i++].id != id) { continue; }
		return true;
	}
	return false;
}

Block *bmem_getById(BMem *bmem, const unsigned int id)
{
	BMem v = bmem[0]; 
    if (v.count == 0) { return NULL; }

	unsigned int i = 0;
    while (i < v.count) {
        if (&(v.loc[i]) == NULL) { i++; continue; }
        if (v.loc[i].id == id) { return &(v.loc[i]); }
        
        i++;
    }
	return NULL;
}

void _bmem_free(BMem *mem) {
	mem->count = 0;
	mem->capacity = 0;
 	memset(mem->loc, 0, mem->capacity);
	free(mem->loc); 
}