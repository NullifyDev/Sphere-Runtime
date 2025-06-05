#ifndef TASK
#define TASK

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Task {
    unsigned int length, 
                 iter;

    unsigned char *content;
    void *returnAddress;
} Task;

// typedef struct Task {
//     unsigned int length, 
//                  iter,
//                 *content,
//                 *returnAddress;

// } Task;

void _task_free(Task *t);
void _task_dumpinsts(Task *t);

#endif
