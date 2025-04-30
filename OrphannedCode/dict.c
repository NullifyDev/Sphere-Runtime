/*
#include "dict.h"

dict *dict_new()
{
    dict *d = malloc(sizeof(dict));
    d->size = 0;
    d->entries = malloc(sizeof(dict_entry) * 16);
    d->capacity = 16;

    return d;
}

void dict_hash_key(char *key, char buf[65])
{
    int i = 0;

    // Use SHA-256 to generate a hash for a key
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, key, strlen(key));
    SHA256_Final(hash, &sha256);

    if (buf == NULL)
    {
        // buf was NULL, this is invalid
        return;
    }

    for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        snprintf(buf + (i * 2), 3, "%02x", hash[i]);
    }

    // Tack on a null terminator
    buf[strlen(buf) - 1] = '\0';
}

void dict_free(dict *d)
{
    for (int i = 0; i < d->size; i++)
    {
        free(d->entries[i].key);
        free(d->entries[i].value);
    }

    free(d->entries);
    free(d);
}

void dict_insert(dict *d, char *key, char *value)
{
    if (d->size == d->capacity)
    {
        d->capacity *= 2;
        d->entries = realloc(d->entries, sizeof(dict_entry) * d->capacity);
    }

    // Generate a hash
    char hash[65];
    dict_hash_key(key, hash);

    d->entries[d->size].hash = strdup(hash);
    d->entries[d->size].value = strdup(value);
    d->size++;
} 
*/
