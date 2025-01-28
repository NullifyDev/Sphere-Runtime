#ifndef TAG
#define TAG

#include <iostream>

struct Tag
{
    int type;
    int size;
    void *loc;
};

static inline const char * tag_numtostr(int type)
{
    switch (type)
    {
        case 1:
            return "bool";
        case 2:
            return "int";
        case 3:
            return "uint";
        case 4:
            return "string";
        default: return "UNKNOWN";
    }
}

inline static struct Tag tag_create(int type, void *location, int size)
{
    struct Tag *tag;

    tag->type = type;
    tag->size = size;

    tag->loc = location == nullptr ? calloc(size, sizeof(Tag)) : location;
}

#endif
