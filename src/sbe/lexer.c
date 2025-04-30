#include "lexer.h"
#include <string.h>
#include <stdio.h>

void *tokenlist_init(unsigned int count) {
    return calloc(sizeof(TokenList *), 1);
}

void wordlist_add(WordList *list, char *key, Token value) {
    list[list->count++].entries = &(WordEntry) {
        .key = key,
        .value = value.opCode
    };
}
void wordlist_addfromarr(WordList *list, WordEntry *entries, size_t count) {
    int i = 0;
    while (i < count)
        list->entries[list->count++] = entries[i++];
}

inline static char *next(int *ptr, const char *src, int nextc) {
    sbe_curr = (int)(nextc == 0 ? 1 : nextc);
    return (char*)peek(0);
}

char peek(int i) {
    return sbe_src[*sbe_curr+i];
}

SrcFile *sbe_init(const char *source) {
    int i = 0, wordcount = 0;
    
    // Skip whitespaces
    while (source[i] == ' ') ;
    
    while (source[i] != '\0')
        if (++i == ' ')
            wordcount++;

    SrcFile *src = &(SrcFile) {
        .line = 1,
        .column = 1,
        .source = source,
        .token = tokendict_init(wordcount),
        .word = words_init(), // never defined? -charlotte
    };
}

void sbe_lex(const char *source) 
{
    SrcFile *src = sbe_init(source);
    int i = 0;

    char word[1024];
    int wi = 0;
    while(peek(0) != '\0' && wi < 1024) {
        switch(peek(0)) {
            case ' ':
                int i = 0;
                while(i < src->word->count){
                    if (strcmp(src->word->entries[i].key, word)) {
                               
                    }
                }
                break; 
            case '\n':
                
                break;
            default:
                break;
        }
        next(&i, source, 0);
    }
}