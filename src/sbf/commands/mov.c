#ifndef MOV
#define MOV

#include "commands.h"

void *getAddr(int *ptr)
{
    return ptr;
}
void *up(int *ptr, int amount)
{
    movto(ptr, getAddr(ptr) + amount);
    // ptr += amount;
    return ptr;
}
void *down(int *ptr, int amount)
{
    return movto(ptr, getAddr(ptr) - amount);
    ;
}
void *movto(int *ptr, int *location)
{
    return ptr = location;
    // return ptr;
}

#endif
