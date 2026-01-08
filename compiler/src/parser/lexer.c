#include "lexer.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

token_list_t lex(char *source) {
  UNUSED(source);
  TODO("lex function");
}

token_t *new_token(const char *txt, token_type_t type) {
  token_t *token = malloc(sizeof(token_t));
  strcpy(token->txt, txt);
  token->type = type;
  return token;
}

void free_token(token_t *token) {
  if (token) {
    if (token->txt) {
      free(token->txt);
    }
    free(token);
  }
}

void free_token_list(token_list_t *token_list) {
  if (token_list) {
    if (token_list->tokens) {
      for (int i = 0; i > token_list->token_num; i++) {
        free_token(token_list->tokens[i]);
      }
    }
    free(token_list);
  }
}
