#include "datatypes.h"
#include "parser/objects/struct.h"

int byte_getKind(void* byte) {
         if ((Variable *)byte != NULL) { return BYTEKIND_VAR; }
    else if ((Function *)byte != NULL) { return BYTEKIND_FUNCTION; }
    else if ((_Struct *) byte != NULL) { return BYTEKIND_STRUCT; }
    else                               { return BYTEKIND_VOID; }
    
}

const char *datatype_getDataType(ByteKind bk) 
{
    switch (bk) 
    {
        case BYTEKIND_INT:   return "INT"; 
        case BYTEKIND_FLOAT: return "FLOAT"; 
        case BYTEKIND_BOOL:  return "BOOL"; 
        case BYTEKIND_CHAR:  return "CHAR"; 
        case BYTEKIND_VOID:  return "VOID"; 
        case DATATYPE_INT:   return "INT"; 
        case DATATYPE_FLOAT: return "FLOAT"; 
        case DATATYPE_BOOL:  return "BOOL"; 
        case DATATYPE_CHAR:  return "CHAR"; 
        case DATATYPE_VOID:  return "VOID"; 
        default:             return  NULL;
    }
}
