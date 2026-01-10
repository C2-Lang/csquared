#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lexer.h"

int main(void) {
  FILE *f = fopen("source.rvn", "r");
  if (!f) {
    perror("Failed to open source.rvn");
    return EXIT_FAILURE;
  }

  fseek(f, 0, SEEK_END);
  long filesize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *src = malloc(filesize + 1);
  fread(src, 1, filesize, f);
  src[filesize] = '\0';
  fclose(f);

  int line_count = 0;
  for (long i = 0; i < filesize; i++) {
    if (src[i] == '\n')
      line_count++;
  }

  clock_t t0 = clock();
  token_list_t *tokens = lex(src);
  clock_t t1 = clock();
  double elapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;

  printf("Lines: %d\n", line_count);
  printf("Used %f%% (%d) of token limit (%d)\n",
         ((double)tokens->token_num / TOKEN_MAX * 100), tokens->token_num,
         TOKEN_MAX);
  printf("Lexing time: %.6f seconds\n", elapsed);

  // _display_token_list(tokens);
  free_token_list(tokens);
  free(src);

  return EXIT_SUCCESS;
}
