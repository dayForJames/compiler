// #include "../include/lexer.h"

// lexer_T* 
// lexer_init(char* src)
// {
//     lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    
//     lexer->src = src;
//     lexer->src_size = strlen(src);
//     lexer->i = 0;
//     lexer->c = src[0];

//     return lexer;
// }

// void 
// lexer_advance(lexer_T* lexer)
// {
//     if (lexer->i < lexer->src_size && lexer->c != '\0')
//     {
//         lexer->i++;
//         lexer->c = lexer->src[lexer->i];
//     }
// }

// token_T* 
// lexer_advance_with(lexer_T* lexer, token_T* token)
// {
//     lexer_advance(lexer);
//     return token;
// }

// void 
// lexer_skip_whitespace(lexer_T* lexer)
// {
//     while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
//     {
//         lexer_advance(lexer);
//     }
// }

// token_T* 
// lexer_parse_id(lexer_T* lexer)
// {
//     char* value = calloc(1, sizeof(char));

//     while (isalpha(lexer->c))
//     {
//         value = realloc(value, (strlen(value) + 2) * sizeof(char));
//         strcat(value, (char[]){lexer->c, 0});
//         lexer_advance(lexer);
//     }

//     return token_init(value, TOKEN_ID);
// }

// char 
// lexer_peek(lexer_T* lexer, int offset)
// {
//     return MIN(lexer->src[lexer->i + offset], lexer->src_size);
// }

// token_T* 
// lexer_next_token(lexer_T* lexer)
// {
//     while (lexer->c != '\0')
//     {
//         if (isalpha(lexer->c))
//         {
//             return lexer_advance_with(lexer, lexer_parse_id(lexer));
//         }

//         switch (lexer->c)
//         {
//             case '=': 
//             {
//                 // if (lexer_peek(lexer, 1) == )
//             }

//         }
//     }

//     return token_init(0, TOKEN_EOF);
// }