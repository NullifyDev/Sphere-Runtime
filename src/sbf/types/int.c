// #include <stdio.h>
// #include <stdlib.h>

// #include "parsing.h"
// #include "../memory.h"

// #define DB_WIDTH (sizeof(size_t))  // DataBus_Width (max byte)

// unsigned char *int_toMem(const size_t n, unsigned char *mem)
// {
//     const unsigned int value = *((unsigned int *)&n);
//     int size = 0;
//     while (1L << (size++ * 8) < value);

//     if (--size > __SIZE_MAX__)
//     {
//         printf("[FATAL ERROR]: CPU UNABLE TO HANDLE BITS HIGHER THAN %d (%d BYTES)! Aborting...", DB_BWIDTH, DB_WIDTH);
//         return;
//     }

//     if (mem == NULL) 
//         mem = malloc(size);

//     unsigned char *ptr = mem;
//     *ptr = size+1;


//     while (--size >= 0) {
//         *(++ptr) = (unsigned char)(value >> (size * 8) & 0xFF);
//     }

//     return mem;
// }

// int int_fromMem(unsigned char *ptr)
// {
//     if (ptr >= protectedMem && ptr <= protectedMem + MEMSIZE) {
//         printf("[RUNTIME: ERROR]: Pointer reached protected memory");
//         return -1;
//     }

//     int value = 0, len = *ptr;
    
//     while (--len >= 0) 
//         value += (unsigned int)(*(++ptr) << ((len * 8) & 0xFF));

//     return value;
// }
