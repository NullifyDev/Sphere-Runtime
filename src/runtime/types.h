#ifndef TYPES
#define TYPES

#include "../sbf/types/datatypes.h"

typedef struct Process {
    long unsigned int Size;
    Function **GlobalFunctions;
    Variable **GlobalVariables;
    Struct **GlobalStructs;
} Process;

static Process **Processes;

#endif
