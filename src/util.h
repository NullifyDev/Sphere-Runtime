#ifndef UTIL
#define UTIL

#include <stdio.h>

inline static int isAlphaNum(char l) {
    return (l >= '0' && l <= '9') ||
           (l >= 'a' && l <= 'z') ||
           (l >= 'A' && l <= 'Z');
}

inline static int isAlpha(char l) {
    return (l >= 'a' && l <= 'z') ||
           (l >= 'A' && l <= 'Z');
}

inline static int isNum(char l) {
    return l >= '0' && l <= '9';   // 0-9
}

inline static int ctoi(char l) {
    printf("ctoi: %d %c\n", (int)l, l);
    return (char)l - '0';
}


#endif
