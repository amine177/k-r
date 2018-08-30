#include <stdio.h>
#include <stdlib.h>

int diff(char *s1, char *s2)
{
  while (*s1++ == *s2++ && *s1 && *s2)
    ;
  if (*--s1 == *--s2)
    return 0;
  return 1;
}
int main(int argc, char *argv[])
{
  FILE *f1, *f2;
  char *prog = argv[0];
  char *line1, *line2;
  size_t *n;
  int n1 = 1000;
  line1 = (char *) malloc(sizeof(char)*1000);
  line2 = (char *)malloc(sizeof(char)*1000);
  n = (size_t *) &n;
  if (argc != 3)
    printf("Usage: diff file1 fiel2");
  else {
    if((f1 = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "%s: cant't open %s\n",
          prog, *argv);
      exit(1);
    } else if ((f2 = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "%s: cant't open %s\n",
          prog, *argv);
      fclose(f1);
      exit(2);
    } else {
      while(getline(&line1, n, f1) != -1 && getline(&line2, n, f2) != -1)
        if (diff(line1, line2)) {
          printf("diffrent on***:\n%s\n****\n%s\n", line1, line2);
          free(line1);
          free(line2);
          return 0;
        }
    }
  }
  free(line1);
  free(line2);
  return 0;
}
