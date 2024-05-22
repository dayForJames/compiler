#include "../include/token.h"

void
updateToken(char* token, const char* c, int* token_cur_size, int* token_max_size, const int* token_init_size)
{   
    if (*token_cur_size >= *token_max_size)
    {
        (*token_max_size) += (*token_init_size);
        token = (char*)realloc(token, sizeof(char) * (*token_max_size + 1));
    }

    token[*token_cur_size] = *c;
    (*token_cur_size)++;

    printf("%d %d\n", *token_cur_size, *token_max_size);
}

void 
updateTokenizer(Token* tokens, const char* token, const int* token_size, int* tokens_cur_size, int* tokens_size, const int* tokens_init_size)
{
    if (*token_size == 0)
    {
        return;
    }

    if (*tokens_cur_size >= *tokens_size)
    {
        (*tokens_size) += (*tokens_init_size);
        tokens = realloc(tokens, sizeof(Token) * (*tokens_size));
    }

    tokens[*tokens_cur_size].value = malloc(sizeof(char) * (*token_size + 1));
    strncpy(tokens[*tokens_cur_size].value, token, *token_size);
    
    tokens[*tokens_cur_size].size = *token_size;
    (*tokens_cur_size)++;
}

Token* 
tokenize(const char* str)
{
    size_t size = strlen(str);

    int tokens_cur_size = 0, tokens_max_size = 10, tokens_init_size = 10;
    Token* tokens = malloc(sizeof(Token) * tokens_init_size);

    int token_init_size = 10, token_max_size = 10, token_cur_size = 0; 
    char* cur_token = malloc(sizeof(char) * token_init_size);

    for (size_t i = 0; i < size; i++)
    {
        if (str[i] != 13 && str[i] != 10 && str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
        {
            updateToken(cur_token, str + i, &token_cur_size, &token_max_size, &token_init_size);
            // printf("%s\n", cur_token);
        }
        else
        {
            // updateTokenizer(tokens, cur_token, &token_cur_size, &tokens_cur_size, &tokens_size, &tokens_init_size);
            free(cur_token);

            token_cur_size = 0;
            token_max_size = token_init_size;

            cur_token = malloc(sizeof(char) * token_init_size);
        }
    }

    return tokens;
}