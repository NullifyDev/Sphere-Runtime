#ifndef VARIABLE
#define VARIABLE

#include "../../datatypes.h"

typedef struct Variable {
    unsigned int id,     // identifiable number
                 pos,    // Position within the data memory 
                 length; // length of data
    DataType type;
} Variable;


#endif
