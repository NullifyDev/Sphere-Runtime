#ifndef OARSER
#define OARSER

#include "../util.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bytecode.h"

typedef struct Token {
	int line;
	int column;
	char *token;
	SbeOpCode opCode;
} Token;

typedef struct TokenList {
	size_t count;
	Token *entries;
} TokenList;


typedef struct WordEntry {
	char *key;
	SbeOpCode value;
} WordEntry;

typedef struct WordList {
	size_t count;
	WordEntry *entries;
} WordList;

typedef struct SrcFile {
	int line;
	int column;
	char *source;
	TokenList *token;
	WordList * word;
} SrcFile;

void *tokendict_init(unsigned int count);
WordList *words_init();
void wordlist_add(WordList *list, char *key, Token value);
void worldlist_addfromarray(WordList *list, WordEntry *entries, size_t count);
void *token_add(Token *t);

static int *sbe_curr;
static char *sbe_src;
SrcFile *sbe_init(const char *source);
void sbe_lex(const char *source);
void sbe_next(int next);
char peek(int i);

#endif
