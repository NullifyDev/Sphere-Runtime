#ifndef BLOCK
#define BLOCK

#include <stdlib.h>

typedef struct Block {
    unsigned int id, length, count; // count is instruction count. length is content's byte count.
    unsigned char *instructions;
    // unsigned int *instructions;
} Block;


void block_free(Block *block);

#endif
