#ifndef BLOCK
#define BLOCK

typedef struct Block {
    int length; // count is instruction count. length is contents array length.
    char *instructions;
} Block;

// void block_loadContents(char *insts, Block *block, int count);

#endif
