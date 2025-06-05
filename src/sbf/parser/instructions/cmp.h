#ifndef CMP
#define CMP

#include "../common.h"
#include "../../bytemgr.h"
#include "../../../util.h"

Value *cmp_parseObj(Thread *thread);
int cmp_compare(Thread *t, Value *lhs, Value *rhs, Value *cond) ;

#endif
