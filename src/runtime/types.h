#ifndef TYPES
#define TYPES

#include "../sbf/types/datatypes.h"

typedef struct Process {
    long unsigned int Size;
    Function **GlobalFunctions;
    Variable **GlobalVariables;
    Struct **GlobalStructs;

	char **ThreadInstPtrs;  // for multi-threading and process managemnt
} Process;

static Process **Processes;

#endif
