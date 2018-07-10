#include <stdio.h>
#include "strutils.h"
#include "conversions.h"

int main(void)
{
  char s[10] = "abc";
  char c[10] = "edc";
  char *sp = s;
  char t[] = " -134";
  char *tp = t;
  char *cp = c;
  char *str;
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
  strncatutil(sp, cp, 3);
  printf("*sp: %s\n", sp);
  printf("%d\n", strncmputil(sp, cp, 2));
  printf("%s\n", itoa(-5002));
  printf("%d\n", atoiconv(tp));
  str = getline_(3);
  printf("%s\n", str);
  return 0;
}
