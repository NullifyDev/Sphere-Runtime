#include "bytemgr.h"
#include "bytecode_init.h"
#include "datatypes.h"
#include "parser/block.h"

#define LEN 44

int main(void) 
{
    unsigned char sbe[LEN] = {
        BYTEKIND_FUNCTION, 0,
        BYTEKIND_BLOCK, 2, 39,
                BYTEKIND_SET, BYTEKIND_VAR, DATATYPE_CHAR, 1, 11, BYTEKIND_CHAR, 11, 'h','e','l','l', 'o', ' ', 'w', 'o', 'r', 'l', 'd',
                BYTEKIND_LOOP,
                    BYTEKIND_BLOCK, 1, 6, 
                        BYTEKIND_CMP, BYTEKIND_INT, 1, BYTEKIND_INT, 1, BYTEKIND_EQ, 
                    BYTEKIND_BLOCK, 1, 8,
                        BYTEKIND_OUTLN, 1, BYTEKIND_VAR, BYTEKIND_GET, 1, BYTEKIND_RET, DATATYPE_VOID, 0,
    };

    Process *proc = process_new("fizzbuzz", 5, 1, 1, 20, 1);

    Thread **threads = proc->threads;
    Thread *t1 = threads[0];

    thread_loadTask(t1, sbe, LEN);
    bytecode_init(t1, 2);

    thread_clearTask(t1);

    Function * f = fmem_getById(t1->fmem, 0);
    Block * blk = bmem_getById(t1->bmem, f->blockId);
    thread_loadTask(t1, blk->instructions, blk->length);

    bytecode_mgr(t1, blk->count);

    return 0;
}