#include "cmp.h"

Value *cmp_parseObj(Thread *thread) {
    return _cmp_parseObj(thread);
}

int cmp_compare(Thread *t, Value *lhs, Value *rhs, Value *cond) 
{
    return _cmp_compare(t, lhs, rhs, cond);
}