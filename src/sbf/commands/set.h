#ifndef SET
#define SET

int set(int *ptr, int value)
{
    return *ptr = value;
    // return *ptr;
}

int incr(int *ptr, int value)
{
    if ()
    *ptr += value;
    return *ptr;
}

int decr(int *ptr, int value)
{
    return *ptr += (value * -1);
    // return *ptr;
}

#endif
