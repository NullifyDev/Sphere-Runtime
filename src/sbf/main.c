#include "bytemgr.h"
#include "bytecode_init.h"
// #include "../runtime/task.h"
#include "datatypes.h"
#include "parser/block.h"
// #include "../runtime/misc/stack.h"

#define LEN 31

int main(void) {
    // printf("loading... \n\n");

    // unsigned int fmem_count = 0, vmem_count = 0, bmem_count = 0, insts_count, mem_count = 0;

    unsigned char sbe[LEN] = 
    {
        BYTEKIND_FUNCTION, 0, 
        BYTEKIND_BLOCK, 2, 23,
            BYTEKIND_SET, BYTEKIND_VAR, DATATYPE_CHAR, 1, 11, BYTEKIND_CHAR, 11, 'h','e','l','l', 'o', ' ', 'w', 'o', 'r', 'l', 'd',
            BYTEKIND_OUTLN, 1, BYTEKIND_VAR, 1, BYTEKIND_RET, DATATYPE_VOID, 0,
    };

    /* bytecode_mgr sees the code above as the following: 
        BYTEKIND_FUNCTION, 0, 
            BYTEKIND_BLOCK, 1, 7, 
                BYTEKIND_OUTLN, 1, BYTEKIND_VAR, 1, BYTEKIND_RET, DATATYPE_VOID, 0,
    */




    // unsigned char sbe[LEN] = 
    // {
    //     BYTEKIND_FUNCTION, 1, 
    //     BYTEKIND_BLOCK, 2, 67,
    //         BYTEKIND_SET, BYTEKIND_VAR, DATATYPE_INT, 1, BYTEKIND_INT, 0,

    //         BYTEKIND_LOOP, 
    //         BYTEKIND_BLOCK, 1, 10, 
    //             BYTEKIND_CMP, BYTEKIND_GETVAL, BYTEKIND_VAR, 1, BYTEKIND_INT, 100, BYTEKIND_LE, BYTEKIND_BLOCK, 0, 0,
                
    //         BYTEKIND_BLOCK, 4, 47,
    //             BYTEKIND_CMP, BYTEKIND_MODULO, BYTEKIND_GETVAL, BYTEKIND_VAR, 1, BYTEKIND_INT, 3, BYTEKIND_INT, 0, 
    //             BYTEKIND_BLOCK, 1, 8, // {
    //                 BYTEKIND_OUT, BYTEKIND_ARR, 4, BYTEKIND_CHAR, 'f', 'i', 'z', 'z',
                    
    //             BYTEKIND_CMP, BYTEKIND_MODULO, BYTEKIND_GETVAL, BYTEKIND_VAR, 1, BYTEKIND_INT, 5, BYTEKIND_INT, 0, 
    //             BYTEKIND_BLOCK, 1, 8,
    //                 BYTEKIND_OUT, BYTEKIND_ARR, 4, BYTEKIND_CHAR, 'b', 'u', 'z', 'z',

    //             BYTEKIND_OUTLN, BYTEKIND_GETVAL, BYTEKIND_VAR, 1,
    //             BYTEKIND_INCR, BYTEKIND_VAR, 1,

    //    BYTEKIND_CALL, 1,
    // };

    // Process *proc = process_new("fizzbuzz", 5, fmem_count, vmem_count, bmem_count, 1);

    Process *proc = process_new("fizzbuzz", 5, 1, 1, 20, 1);

    Thread **threads = proc->threads;
    Thread *t1 = threads[0];


    /*
        // TO BE ADDED: INTEGER DB

        unsigned int sbe_uints[1] = { 0 } 
    */

    // 

    /* Human-readable bytecode - direct translation:
        (2, 70) {
            func1 (2 63) {
                set (var int 1), (int)0
                while (1 6) { if (var)1, (int)100, le ) }
                    (4 42) {
                        if (mod (var)1, (int)3)), (int)0 
                            (1 8) {
                                out (char[4])"fizz"
                            }
                        if (mod (var)1, (int)5)), (int)0 
                            (1 8) {
                                out (char[4])"buzz"
                            }

                        outln (var)1
                        incr  (var)1
                        // ret 0
                    }
            }

            call 1
        }
    */



    thread_loadTask(t1, sbe, LEN);
    bytecode_init(t1, 2);

    thread_clearTask(t1);
    Function * f = fmem_getById(t1->fmem, 0);
    Block * blk = f->contents;
    thread_loadTask(t1, blk->instructions, blk->length);
    // printf("done!\n");


    bytecode_mgr(t1, blk->count);



    // printf("\n[END OF RUNTIME]\n");

    // printf("mem\n");
    // if (t1->mem->count > 0) {
    //     for (unsigned int i = 0; i < t1->mem->capacity; i++) 
    //         printf("%d ", (int)t1->mem->loc[i]);
        
    //     printf("\n");
    // }   

    return 0;
}