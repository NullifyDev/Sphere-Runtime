// #ifndef SPHERE_DICT_IMPL
// #define SPHERE_DICT_IMPL

// #include <stdlib.h>
// #include <stdint.h>
// #include <string.h>
// #include "types/manager.h"

// // TODO: maybe you want to replace this with your own implementation
// // if you want full portability later on with your weird CPU architecture
// // but for the sake of a working prototype, im not doing all that
// #include <openssl/sha.h>

// typedef struct
// {
//     char hash[65];
//     TypeID type;
//     void *value;
// } dict_entry;

// typedef struct
// {
//     dict_entry *entries;
//     size_t size;
//     size_t capacity;
// } dict;

// dict *dict_new();

// void dict_hash_key(char *key, char buf[65]);
// void dict_free(dict *d);
// void dict_insert(dict *d, char *key, TypeID type, void *value);
// void dict_remove(dict *d, char *key, TypeID type);

// #endif