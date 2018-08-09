#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int (*PF)(int), c;

  if (argc != 2) {
fail:
    printf("Usage:\n convert [-u|-l]\n");
    exit(1);
  }
  
  switch (*(++argv[1])) {
    case ('u'):
      PF = toupper;
      break;
    case ('l'):
      PF = tolower;
    default:
      goto fail;
  }

  while ((c = getchar()) != EOF)
    putchar((*PF)(c));

  return 0;
}
