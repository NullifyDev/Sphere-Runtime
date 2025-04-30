#include <stdlib.h>
#include <stdio.h>

#include "datatypes.h"
#include "parser/common.h"
#include "../runtime.h"
#include "bytemgr.h"

int main(void) {
    Process *proc = process_new("fizzbuzz", 16, 1, 1, 1);

    Thread *threads = proc->threads;
    Thread *t = &threads[0];

    char sbe[] = {
        // FUNCTION ID INSTRUCTION_COUNT
        BYTEKIND_FUNCTION, 1, 44,
            // SET (TYPE ID: TYPE) = O
            BYTEKIND_SET, BYTEKIND_VAR, 1, BYTEKIND_INT, 0,
            // LOOP CMP VAR0 100 LE
            BYTEKIND_LOOP, BYTEKIND_CMP, BYTEKIND_VAR, 1, 100, BYTEKIND_LE,
                // BLOCK 4
                BYTEKIND_BLOCK, 4,
                    // CMP (MOD VAR0 3) 0 EQ, OUT "FIZZ"
                    BYTEKIND_CMP, BYTEKIND_MODULO, BYTEKIND_VAR, 1, 3, 0, BYTEKIND_OUT, BYTEKIND_CHAR, 4, 'f', 'i', 'z', 'z',
                    // CMP (MOD VAR0 5) 0 EQ, OUT "BUZZ"
                    BYTEKIND_CMP, BYTEKIND_MODULO, BYTEKIND_VAR, 1, 5, 0, BYTEKIND_OUT, BYTEKIND_CHAR, 4, 'b', 'u', 'z', 'z',
                    // OUTLN 
                    BYTEKIND_OUTLN, 0,
                    // INCR VAR0
                    BYTEKIND_INCR, BYTEKIND_VAR, 1,
    };

    thread_loadTask(t, sbe);

    bytecode_mgr(t, t->task.length);

    printf("%d\n", sbe[0]);

    return 0;
}