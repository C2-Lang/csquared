#ifndef INCLUDE_INCLUDE_LEXER_H_
#define INCLUDE_INCLUDE_LEXER_H_

typedef enum { T_EOF } token_type_t;

typedef struct {
  char *txt;
  token_type_t type;
} token_t;

typedef struct {
  token_t **tokens;
  int token_num;
} token_list_t;

token_list_t lex(char *source);

token_t *new_token(const char *txt, token_type_t type);
void free_token(token_t *token);
void free_token_list(token_list_t *token_list);

#endif // INCLUDE_INCLUDE_LEXER_H_
