#include "datatypes.h"

int ManageID(unsigned char *memPtr, unsigned char *instPtr, unsigned char type)
{
    switch (*instPtr)
    {
    case TYPE_VOID:
        printf("[%d]: TYPE_VOID\n", *instPtr);
        break;

    case TYPE_BOOL:
        printf("[%d]: TYPE_BOOL\n", *instPtr);
        break;

    case TYPE_STR:
        printf("[%d]: TYPE_STR\n", *instPtr);
        break;

    /*
        19 - 64: RESERVED (DATA) TYPES!!!
        19 - 64: RESERVED (DATA) TYPES!!!
        19 - 64: RESERVED (DATA) TYPES!!!
        19 - 64: RESERVED (DATA) TYPES!!!
        19 - 64: RESERVED (DATA) TYPES!!!
    */

    // Instructions - General
    case TYPE_MOV:
        printf("[%d]: TYPE_MOV\n", *instPtr);
        break;

    case TYPE_UP:
        printf("[%d]: TYPE_UP\n", *instPtr);
        break;

    case TYPE_DOWN:
        printf("[%d]: TYPE_DOWN\n", *instPtr);
        break;

    case TYPE_SET:
        printf("[%d]: TYPE_SET\n", *(instPtr++));
        ManageID(memPtr, instPtr, TYPE_SET);
        break;

    case TYPE_INCR:
        printf("[%d]: TYPE_INCR\n", *instPtr);
        break;

    case TYPE_DECR:
        printf("[%d]: TYPE_DECR\n", *instPtr);
        
        break;

    case TYPE_PRINT:
        printf("[%d]: TYPE_PRINT\n", *instPtr);
        break;

    case TYPE_PRINTLN:
        printf("[%d]: TYPE_PRINTLN\n", *instPtr);
        break;

    case TYPE_FOR:
        printf("[%d]: TYPE_FOR\n", *instPtr);
        break;

    case TYPE_FOREACH:
        printf("[%d]: TYPE_FOREACH\n", *instPtr);
        break;

    case TYPE_WHILE:
        printf("[%d]: TYPE_WHILE\n", *instPtr);
        break;

    case TYPE_INVOKE:
        printf("[%d]: TYPE_INVOKE\n", *instPtr);
        break;

    // Instructions - Definitions
    case TYPE_DEF_FUNC:
        printf("[%d]: TYPE_DEF_FUNC\n", *instPtr);
        break;
    case TYPE_DEF_OBJ:
        printf("[%d]: TYPE_DEF_OBJ\n", *instPtr);
        
        break;

    default:
        if (*instPtr >= TYPE_INT && *instPtr < TYPE_STR)
        {
            // *(memPtr++) = *instPtr;
            printf("[%d]: Type: int (len: %d)\n", *(instPtr - 1), *(instPtr++) - 1);
            if (type == TYPE_SET)
            {
                //  *int_toMem(*instPtr, memPtr);
            }
            else if (type == TYPE_GET)
            {
                // return int_fromMem(memPtr);
            }
        }
        else if (*instPtr > 64 && *instPtr < 19)
        {
            printf("[%d]: Reserved Data Type\n", *instPtr);
        }
        else
        {
            printf("[%d]: Unknown ID\n", *instPtr);
        }
        break;
    }
}