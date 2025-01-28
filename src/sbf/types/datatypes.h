#ifndef DATATYPE
#define DATATYPE

#ifdef __unix__ 
    #include <stdio.h>
#else 
    #include "./../commands/print.h"
#endif

#define SIZE_T long unsigned int;

typedef enum
{
    TYPE_VOID = 0,
    TYPE_BOOL,
    TYPE_INT,
    TYPE_STR,
    TYPE_MOV,
    TYPE_UP,
    TYPE_DOWN,
    TYPE_SET,
    TYPE_GET,
    TYPE_INCR,
    TYPE_DECR,
    TYPE_PRINT,
    TYPE_PRINTLN,
    TYPE_FOR,
    TYPE_FOREACH,
    TYPE_WHILE,
    TYPE_INVOKE,
    TYPE_GET_TAG,
    TYPE_DEF_FUNC,
    TYPE_DEF_OBJ,
} TypeID;

typedef struct Variable {
    TypeID type;
    char attribute;
    long unsigned int length;       // if more than 1, array
    union value {
        int *integer;
        char *boolean;    // if higher than 0, true
        char *character;
        union arr {
            void *contiguous;
            void **incontiguous;
        } arr;
    } value;
} Variable;

typedef struct Function {
    char attributes;
    Variable **reutrnObj;
    Variable **parameters;
    char *codeblock;
} Function;

typedef struct Struct {
    Function **Functions;
    Variable **Variables;
} Struct;

int ManageID(unsigned char *memPtr, unsigned char *instPtr, unsigned char type);

#endif