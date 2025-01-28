#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <string.h>

inline static int *combine_arr(int *a, int alen, int *b, int blen) {
    printf("combine_arr: called\n");
    printf("\n\n");
    printf("a: [ ");
    for(int i = 0; i < alen; i++) {
        printf("%d ", *(a+i));
    }
    printf("]: %d\n", alen);
    printf("b: [ ");
    for(int i = 0; i < blen; i++) {
        printf("%d ", *(b+i));
    }
    printf("]: %d\n\n", blen);

    int mem[alen+blen];
    int *arr = mem;
    int i = 0;
    for (; i < alen; i++) {
        *(arr+i) = *(a+i);
    }
    for (int j = 0; j < blen; j++, i++) {
        *(arr+i) = *(b+j);
    }
    return arr;
}

inline static int first_null(int *src, int len) {
    for (int i = 0; i < len; i++) {
        if (*src == 0) return i;
    }
    return -1;
}

#endif
