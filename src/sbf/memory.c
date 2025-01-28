// #include <stdlib.h>

// #include "./memory.h"

// int IsProtectedPointed(void *ptr)
// {
//     return (ptr >= (void *)protectedMem && ptr <= (void *)protectedMem + MEMSIZE);
// }

// void *_free(unsigned char *ptr)
// {
//     if (IsProtectedPointed(ptr) == 1)
//         return NULL;

//     int size = *ptr, i = -1;
//     while (++i < size)
//         *(ptr + i) = 0;

//     return 0;
// }

// Memory *memory_init(int size)
// {
//     int dsize = size/2 , lsize = (size/2) * sizeof(Label);
//     Memory *mem = malloc(1 * sizeof(&(Memory) {
//         .Data = malloc(dsize),
//         .DataSize = dsize,
//         .LabelSize = lsize,
//         .Label = malloc(lsize * sizeof(Label))
//     }));
//     return mem;
// }
