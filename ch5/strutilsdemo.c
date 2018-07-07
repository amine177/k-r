#include <stdio.h>
#include "strutils.h"

int main(void)
{
  char s[10] = "abc";
  char c[10] = "edc";
  char *sp = s;
  char t[] = "efg";
  char *tp = t;
  char *cp = c;
  strcatutil(sp, tp);
  printf("%s\n", sp);
  printf("%d\n", strendutil(sp, "rg"));
  printf("&s: %x\n", s);
  printf("sp: %x\n", sp);
  printf("&c: %x\n", c);
  printf("cp: %x\n", cp);
  strncpyutil(sp, cp, 4);
  printf("*sp: %s\n", s);
  printf("*cp: %s\n", cp);
  printf("cp: %x\n", cp);
  printf("c[0]: %c\n", c[0]);
  return 0;
}
