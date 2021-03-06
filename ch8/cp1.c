#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define PERMS 0666
#undef BUFSIZ
#define BUFSIZ 1024


void error(char *, ...);

int main(int argc, char *argv[])
{
  int src, dst;
  int n;
  char buf[BUFSIZ];

  if (argc != 3) {
    return -1;
  }

  src = open(*++argv, O_RDONLY, 0);
  dst = creat(*++argv, PERMS);

  while ((n = read(src, buf, sizeof buf)) > 0)
    write(dst, buf, n);

  return 0;
}

void error(char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  fprintf(stderr, "error: ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, fmt, args);
  va_end(args);

  exit(1);
}
