#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    void **content; 
    unsigned int count, length;
} Stack;

Stack *stack_new   (unsigned int capacity);
void   stack_pop   (Stack *stack);
void   stack_push  (Stack *stack, void *item);
void   stack_flush (Stack *stack);
void  *stack_getTop(Stack *stack);

void  _stack_free  (Stack *s);
#endif