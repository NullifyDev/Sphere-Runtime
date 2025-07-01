#ifndef VALUE
#define VALUE

#include "../../datatypes.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct Value 
{
    ByteKind type;
    char *value;        // use of this is based on Value.type
    int length; 
    bool isNull;        
} Value;

Value *value_new (ByteKind datatype, int length, char *value);
Value *value_newV(ByteKind type,                 char value);
void value_free(Value *v);

#endif
