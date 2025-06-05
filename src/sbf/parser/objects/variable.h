#ifndef VARIABLE
#define VARIABLE

#include "../../datatypes.h"
#include "../datatype/common.h"
// A pointer pointing to the data memory (mem). resides in variable memory (vmem)
typedef struct Variable {
    unsigned int id,     // identifiable number
                 pos,    // Position within the data memory 
                 length; // length of data

    bool isNull;
    ByteKind type;
} Variable;

void value_toVariable(Value *val, Variable *var);
void var_toValue(Variable *var, Value *val);

#endif
