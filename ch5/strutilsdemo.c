#include <stdio.h>
#include "strutils.h"

int main(void)
{
  char s[10] = "abc";
  char *sp = s;
  char t[] = "efg";
  char *tp = t;
  strcatutil(sp, tp);
  printf("%s\n", sp);
  printf("%d\n", strendutil(sp, "rg"));
  return 0;
}
