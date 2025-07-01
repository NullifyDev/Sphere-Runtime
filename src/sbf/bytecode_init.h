#ifndef BYTECODE_INIT
#define BYTECODE_INIT

#include <stdlib.h>
#include <stdbool.h>

#include "../util.h"
#include "datatypes.h"
#include "../runtime.h"

#include "parser/common.h"
#include "../runtime/error.h"
#include "parser/bytekind/value.h"
#include "parser/datatype/value.h"
#include "parser/datatype/common.h"

void *bytecode_init(Thread *t, unsigned int inst_count);

inline static Block *block_new(unsigned int id, unsigned int count, unsigned int length) 
{
    Block *blk = (Block *)calloc(1, sizeof(Block));
    blk->id = id;
    blk->count = count;
    blk->length = length;
    blk->instructions = NULL;
    return blk;
}
inline static void block_load(Block *block, unsigned char *instructions)
{   
    block->instructions = instructions;
}

inline static Function *func_new(Thread *t, unsigned int id, int block_id) 
{
    if (t->fmem->count >= t->fmem->capacity) 
    {
        printf("\033[1m\033[38;2;255;0;0mERROR:\033[0m func_new: function list is full can only hold %d amount of functions\n", t->fmem->capacity);
        return NULL;
    }

    Function *f = &t->fmem->loc[t->fmem->count];
    f->id = id;
    f->blockId = block_id;

    return f;
}

#endif
