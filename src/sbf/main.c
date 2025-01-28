// // #include "runtime.h"
// #include <stdio.h>
// #include <time.h>

// #include "./commands/commands.h"
// #include "./types/datatypes.h"

// // #define cpuBit (sizeof(unsigned size_t)*8)

// int main() {


//     // tagMem       = malloc(sizeof(Tag) * size);
//     // tPtr         = tagMem; 

//     // init(16);

//     // Memory *mem = memory_init(16);

//     unsigned char mem[16];
//     unsigned char *mPtr = mem;

//     unsigned char input[] = {
//         TYPE_DEF_OBJ, TYPE_STR, 2,
//         TYPE_INT, 72,
//         TYPE_INT, 105,
//     };
//     int i = 0;

//     clock_t begin = clock();
//     ManageID(mPtr, &input[i], 0);
//     clock_t end = clock();

//     long time_spent = (long)(end - begin);
//     printf("\nRuntime: %ldμs\n", time_spent);

//     // printf("\n%d\n[%d] Data: [ ", sizeof(mem), mem->DataSize);
//     // int j = 0;
//     // while(j < mem->DataSize) {
//     //     printf("%d ", *(protectedMem+(j++)));
//     // }
//     // printf("]\n");


//     // free(mem);

//     // tPtr--;
//     // printf("Tag:  [ ");
//     // while(++tPtr < tagMem + size) {
//     //     printf("%d %d %d ", tPtr->type, tPtr->addr, tPtr->len);
//     // }
//     // printf("]: %d\n");

//     return 0;
// }
