/* THIS HEADER HAS INLINE FUNCTIONS TO COUNTER/AVOID INCLUDE RECURSIONS */

#ifndef BYTEMGR
#define BYTEMGR

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

void *bytecode_mgr(Thread *thread, unsigned int len);
bool  atEnd(Stack *t, unsigned int ahead);
unsigned char   peek(Stack *task, unsigned int ahead);
unsigned char  *peek_ptr(Stack *t, unsigned int ahead);
unsigned char   next(Stack *task, unsigned int ahead);
unsigned char *next_ptr(Stack *t, unsigned int ahead);

inline static char _cmp_isOp(char byte) {
    switch (byte) 
    {
        case BYTEKIND_LT: 
        case BYTEKIND_GT:
        case BYTEKIND_LE:
        case BYTEKIND_GE:
        case BYTEKIND_EQ:
        case BYTEKIND_NE:
            return byte;
        
        default: return 0;
    }
    return 0;
}

inline static Value *_cmp_parseObj(Thread *thread) {
    char node = next(thread->task, 1);
        //  res = '\0';

    Value *val = value_new(BYTEKIND_NULL, 0, 0);

    switch(node) {
        case BYTEKIND_VAR:
            char i = next(thread->task, 1);
            Variable *v = vmem_getById(thread->vmem, i);
            // Value *v = (Value *)bytecode_mgr(thread, 1); // vmem_getById(thread->vmem, next(thread->task, 1));
            
            
            if (v->isNull) {
                val->isNull = v->isNull;
                return val;
            }

            val->type = v->type;
            val->length = v->length;
            val->value = &thread->mem->loc[v->pos];

            // next(thread->task, 1);



            return val;
            
        case BYTEKIND_FUNCTION:
            Function *f = fmem_getById(thread->fmem, next(thread->task, 1));
            if (f == NULL) return NULL;
            
            Block *b = bmem_getById(thread->bmem, f->blockId);

            thread_loadTask(thread, b->instructions, b->length);
            val = (Value *)bytecode_mgr(thread, b->length);

            free(val);
            // next(thread->task, 1);

            return f->returnAddr;
            // return v == NULL ? NULL : bytecode_mgr(thread, ) &thread->mem->loc[thread->fmem->loc[(int)peek(thread->task, 0)].pos];

        case BYTEKIND_STRUCT:
            printf("[INTERNAL ERROR]: Struct cannot be parsed just yet - coming soon\n");
            // next(thread->task, 1);
            return value_new(BYTEKIND_STRUCT, 0, 0);

        case BYTEKIND_INT:
            char num = next(thread->task, 1);
            // val = value_newV(BYTEKIND_INT, num);
            // next(thread->task, 1);
            return value_newV(BYTEKIND_INT, num);

        case BYTEKIND_MODULO:
            val = (Value *)bytecode_mgr(thread, 1);
            next(thread->task, 1);
            return val;



        default:
            char c = _cmp_isOp(node);
            if (c != 0) { 
                val = value_newV((ByteKind)c, c); 
                // next(thread->task, 1);
                return val;
            }

            printf("_cmp_parseObj: ");
            Value* val = (Value*)bytecode_mgr(thread, 1);
            if (val == NULL) printf("bytecode_mgr returned NULL\n");
            return val;
    }

    return val;
}

inline static int _cmp_compare(Thread *t, Value *lhs, Value *rhs, Value *cond) 
{
    bool res = false;
    switch (cond->type) 
    {
        case BYTEKIND_EQ: res = (*lhs->value == *rhs->value); break; 
        case BYTEKIND_NE: res = (*lhs->value != *rhs->value); break; 
        case BYTEKIND_LT: res = (*lhs->value <  *rhs->value); break; 
        case BYTEKIND_LE: res = (*lhs->value <= *rhs->value); break; 
        case BYTEKIND_GT: res = (*lhs->value >  *rhs->value); break; 
        case BYTEKIND_GE: res = (*lhs->value >= *rhs->value); break; 
        default: 
            // error_out(BYTEKIND_CMP | 1);
            printf("[INTERNAL ERROR]: _cmp_compare: unrecognised condition type: %d @ %d:%d\n", (int)cond->type, t->task->count, ((Task *)stack_getTop(t->task))->iter);
            exit(1);
            break;
    }

    return res;
}

inline static void *_block_run(Thread *t, Block *b)
{
    if (b == NULL) 
    {
        printf("_block_run: block parameter is null\n");
        return NULL;
    }

    // next(t->task, 1);
    if (b->length < 1 || b->count < 1) 
    {
        next(t->task, 1);
        return NULL;
    }

    thread_loadTask(t, b->instructions, b->length);
    void *res = bytecode_mgr(t, b->count);
    thread_popTask(t);
    return res;
}

inline static void *_block_runid(Thread *t, unsigned int bid)
{
    Block *b = bmem_getById(t->bmem, bid);
    if (b == NULL) 
    {
        printf("_block_runid: parameter \"bid\" with value %d does not refer to a declared block\n", bid);
        return NULL;
    }

    // next(t->task, 1);
    if (b->length < 1 || b->count < 1) 
    {
        next(t->task, 1);
        return NULL;
    }

    thread_loadTask(t, b->instructions, b->length);
    next(t->task, 1);
    return bytecode_mgr(t, b->count);
}

inline static Block *_block_getById(Thread *t, unsigned int id)
{
    unsigned int i = 0;
    while(i < t->bmem->capacity) {
        if (t->bmem->loc[i].id == id) return &t->bmem->loc[i];
        i++;
    }

    return NULL;
}

inline static int _func_run(Thread *t, int id)
{
    if (!fmem_hasId(t->fmem, id)) {
        printf("[RUNTIME ERROR]: Function %d: does not exist - aborting\n", id);
        exit(1);
    }

    Function *f = fmem_getById(t->fmem, id);
    _block_runid(t, f->blockId);
    return 0;
}

#endif
