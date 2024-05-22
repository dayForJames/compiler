#ifndef NEW_ASM_TOKEN_H
#define NEW_ASM_TOKEN_H

#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

typedef enum TokenType
{
    _return,
    int_lit,
    semi,
} TokenType;

typedef struct Token
{
    TokenType type;
    size_t size;
    char* value;
} Token;

Token* tokenize(const char* str);
void updateToken(char* token, const char* c, int* token_cur_size, int* token_size, const int* token_init_size);
void updateTokenizer(Token* tokens, const char* token, const int* token_size, int* tokens_cur_size, int* tokens_size, const int* tokens_init_size);

#endif