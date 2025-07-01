#include "block.h"

void block_free(Block *block) 
{
    if (block == NULL) return;
    
    block->id = 0;
    block->count = 0;
    block->length = 0;

    block->instructions = NULL;
    free(block->instructions);
    
    free(block);
}
