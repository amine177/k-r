#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if (argc == 1)
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL) {
        printf("cat: can't open %s\n", *argv);
        return 1;
      } else {
        filecopy(fp, stdout);
        fclose(fp);
      }
}


void filecopy(FILE *s, FILE *d)
{
  int c;

  while ((c = getc(s)) != EOF)
    putc(c, d);
}
