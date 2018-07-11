#include <stdio.h>


int main(int argc, char *argv[])
{
  if (argc == 1)
    printf("Usage: echo arg1 arg2 ...\n");
  else
    while (*argv)
      printf("%s\n", *++argv);
  return 0;
}
