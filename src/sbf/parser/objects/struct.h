#ifndef STRUCT
#define STRUCT

#include "function.h"
#include "variable.h"

typedef struct _Struct {
    int id, funccount, varcount;
    Function *Functions;
    Variable *Variables;
} _Struct;

#endif
