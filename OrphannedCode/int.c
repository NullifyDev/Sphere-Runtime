#include <stdio.h>

#define DB_WIDTH (sizeof(size_t))  // DataBus_Width (max byte)

unsigned char *int_toMem(const size_t n, unsigned char *mem)
{
    const unsigned int value = *((unsigned int *)&n);
    int size = 0;
    while (1L << (size++ * 8) < value);

    if (--size > __SIZE_MAX__)
    {
        printf("[FATAL ERROR]: CPU UNABLE TO HANDLE BITS MORE THAN %d! Aborting...", DB_WIDTH * 8);
        return;
    }

    if (mem == NULL) 
        mem = malloc(size);

    unsigned char *ptr = mem;
    *ptr = size+1;


    while (--size >= 0) {
        *(++ptr) = (unsigned char)(value >> (size * 8) & 0xFF);
    }

    return mem;
}

int int_fromMem(unsigned char *ptr)
{
    int value = 0, len = *ptr;
    
    while (--len >= 0) 
        value += (unsigned int)(*(++ptr) << ((len * 8) & 0xFF));

    return value;
}
