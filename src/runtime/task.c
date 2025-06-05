#include "task.h"

void _task_free(Task *t) {
    t->iter = 0;
    t->length = 0;
    memset(t->content, 0, t->length);
    free(t->content);
}

void _task_dumpinsts(Task *t) 
{
    unsigned i = 0;
    printf("_task_dumpinsts: [ ");
    while(i < t->length)
        printf("%d ", t->content[i++]);
    
    printf("]\n");
}