#include "error.h"

void error_out(int error) //, void *obj)
{
    int loc = error >> 8;
    switch(loc) {
        case BYTEKIND_INCR:
            printf("incr: ");
            switch (error - (loc << 8)) 
            {
                case 0:  printf("\n"); error = 0; break;
                case 1:  printf("improper target - must be either pointer, variable, invocation, address or value\n"); break;
                case 2:  printf("improper incrementation - must be either pointer, variable, invocation, address or value\n"); break;
                default: printf("unknown error (%d)\n", error); break;
            }
            break;
        case BYTEKIND_DECR:
            printf("decr: ");

            switch (error - (loc << 8))
            {
                case 0:  printf("\n"); error = 0; break;
                case 1:  printf("improper target - must be either pointer, variable, invocation, address or value\n"); break;
                case 2:  printf("improper incrementation - must be either pointer, variable, invocation, address or value\n"); break;
                default: printf("unknown error (%d)\n", error); break;
            }
            break;
        case BYTEKIND_VAR:
            printf("var: ");
            // Variable *var = obj;
            switch (error - (loc << 8))
            {
                case 0:  printf("\n"); error = 0; break;
                case 1:  printf("no such variable found\n"); break; //, var->id); break;
                case 2:  printf("unknown type\n"); break;
                default: printf("unknown error (%d)\n", error); break;
            }
            break;
        default: printf("ERROR: error_out: Unknown error tpye (%d-%d)", error >> 8, error & loc); break;
    }
    // free(obj);
    if (error > 0) exit(error);
}