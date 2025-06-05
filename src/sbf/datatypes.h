#ifndef DATATYPE
#define DATATYPE

#ifdef __unix__ 
    #include <stdio.h>
#else 
    #include "./../commands/print.h"
#endif

// Negative Enums are Internal
typedef enum ByteKind {
    BYTEKIND_STATUS = -2,
    BYTEKIND_ERROR,
    
    BYTEKIND_NOOP,
    BYTEKIND_NULL,
    BYTEKIND_VOID,
    BYTEKIND_INT,
    BYTEKIND_FLOAT,
    BYTEKIND_BOOL,
    BYTEKIND_CHAR,
    DATATYPE_INT,
    DATATYPE_FLOAT,
    DATATYPE_BOOL,
    DATATYPE_CHAR,
    DATATYPE_STRUCT,
    DATATYPE_VOID,
    DATATYPE_NONE,
    BYTEKIND_VAR,
    BYTEKIND_ARR,
    BYTEKIND_FUNCTION,
    BYTEKIND_STRUCT,
    BYTEKIND_CALL,
    BYTEKIND_UP,
    BYTEKIND_DOWN,
    BYTEKIND_MOV,
    BYTEKIND_INCR,
    BYTEKIND_DECR,
    
    BYTEKIND_SET,
    
    BYTEKIND_GET,
    BYTEKIND_GETVAL,
    BYTEKIND_GETLOC,

    BYTEKIND_CMP,
    BYTEKIND_EQ,
    BYTEKIND_NE,
    BYTEKIND_LT,
    BYTEKIND_LE,
    BYTEKIND_GT,
    BYTEKIND_GE,
    BYTEKIND_IS,
    BYTEKIND_ISNT,
    BYTEKIND_BLOCK,
    BYTEKIND_OUT,
    BYTEKIND_OUTLN,
    BYTEKIND_LOOP,
    BYTEKIND_CONCATENATE,
    BYTEKIND_LOC,
    BYTEKIND_INFO,
    BYTEKIND_MODULO,
    BYTEKIND_RET,

    BYTEKIND_HLT,
} ByteKind;

int byte_getKind(void*);
const char *datatype_getDataType(ByteKind bk);

// typedef enum DataType {
//     // DataType reflects the enum value of ByteKind 
//     DATATYPE_INT = -7,
//     DATATYPE_FLOAT,
//     DATATYPE_BOOL,
//     DATATYPE_CHAR,
//     DATATYPE_STRUCT,
//     DATATYPE_VOID,
//     DATATYPE_NONE
// } DataType;

// ByteKind bytekind_toDatatype(int b);
// ByteKind datatype_toBytekind(int b);

#endif
