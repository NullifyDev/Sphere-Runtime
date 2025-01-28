#ifndef PRINT
#define PRINT

#include <stdio.h>
#include <string.h>

#include "../types/ids.h"
#include "utils.h"
#include "../types/parsing.h"

#ifndef out
#define out(x) _print(x, false)
#endif

#ifndef outln
#define outln(x) _print(x, true)
#endif

inline static void _print(unsigned char *ptr, bool breakline)
{
    int argc = *ptr;

    for (int i = 0; i < argc; i++)
    {
        int literalType = *(++ptr);
        int literalLength = *(++ptr);

        switch (literalType)
        {
            case TYPE_VOID:
                break;
            case TYPE_BOOL:
                for (int j = 0; j < literalLength; j++)
                {
                    printf(*(++ptr) >= 1 ? "true" : "false");
                }
                break;
            case TYPE_INT:
            {
                printf("%d", );
                break;
            }
            case TYPE_STR:
                for (int j = 0; j < literalLength; j++)
                    printf("%c", *(++ptr));

                break;
        }
        printf(" ");
    }
    if (breakline)
        printf("\n");
}

#endif
