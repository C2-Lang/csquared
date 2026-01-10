#include "rvnutils.h"
#include <string.h>

void strcatchr(char *str, char c) {
  char concat_c[2] = {c, '\0'};
  strcat(str, concat_c);
}
