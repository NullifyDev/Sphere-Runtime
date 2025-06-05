#ifndef BMEM
#define BMEM

#include <stdlib.h>
#include <stdio.h> 
#include <stdbool.h>
#include <string.h>

#include "../../sbf/parser/block.h"

typedef struct BMem {
    Block *loc;
    unsigned int capacity, count;
} BMem;



int       _bmem_firstUnused (BMem *bmem);
bool      _bmem_occupiedAddr(BMem *bmem, const unsigned int loc);
bool      _bmem_isEmpty     (Block *var);
void      _bmem_free        (BMem *bmem);

BMem      *bmem_new         (            const unsigned int capacity);
void       bmem_add         (BMem *bmem, Block *blk);
Block     *bmem_getById     (BMem *bmem, const unsigned int id );
bool       bmem_hasId       (BMem *bmem, const unsigned int id );

#endif
