#include "stack.h"

Stack *stack_new(unsigned int capacity) {
    Stack *s = calloc(1, sizeof(Stack));
    s->length = capacity;
    s->count = 0;
    s->content = calloc(1, capacity);

    return s;
}

void stack_pop(Stack *stack) 
{
    if (stack->count <= 0) {
        printf("Runtime: stack: Unable to remove top-most item - already empty (skipping)\n");
        return;
    }

    free(stack->content[stack->count--]);
}

void stack_push(Stack *stack, void *item) {
    if(stack->count >= stack->length) {
        printf("Runtime: stack: Unable to add item to stack - already full (skipping)\n");
        return;
    }

    stack->content[stack->count++] = item;
}

void *stack_getTop(Stack *s) {
    return s->content[s->count-1];
}

void stack_flush(Stack *s)
{
    while(s->count > 0)
        stack_pop(s);

    stack_pop(s);
}

void _stack_free(Stack *s)
{
    stack_flush(s);
    free(s);
}

// void *stack_getTop(Stack *stack) {
//     printf("[%p]: stack[count].content = (%p) | length: %d | count: %d\n", stack, stack[stack->count-1].content, stack->length, stack->count);
//     return stack->content + (stack->count-1);
// }
