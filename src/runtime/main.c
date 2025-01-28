// #include "runtime.h"
#include <stdio.h>
#include <time.h>

#include "types.h"

int main() {
    unsigned char mem[16];
    unsigned char *mPtr = mem;

    unsigned char input[] = {
        TYPE_DEF_OBJ, TYPE_STR, 2,
        TYPE_INT, 72,
        TYPE_INT, 105,
    };
    int i = 0;

    clock_t begin = clock();
    ManageID(mPtr, &input[i], 0);
    clock_t end = clock();

    long time_spent = (long)(end - begin);
    printf("\nRuntime: %ldμs\n", time_spent);
}