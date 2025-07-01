#include "value.h"


Value *value_new(ByteKind type, int length, char *value) 
{
    Value *v = (Value*)calloc(1, sizeof(Value));
    v->type = type;
    v->length = length;
    v->value = value;
    return v;
}

Value *value_newV(int type, char value) 
{
    Value *v = (Value*)calloc(1, sizeof(Value));
    v->type = type;
    v->length = 1;

    char *val = calloc(1, sizeof(char));
    val[0] = value;
    v->value = val;
    return v;
}

void value_free(Value *v)
{
    v->value = 0;
    v->isNull = 0;
    v->length = 0;
    v->type = 0;
    free(v);
}