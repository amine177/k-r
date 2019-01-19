#include <fcntl.h>
#include <sys/types.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


void error(char*, ...);
void copy(int, int);

int main(int argc, char *argv[])
{
  int f1;

  if (argc == 1)
    copy(0, 1);

  while (--argc) {
    if ((f1 = open(*++argv, O_RDONLY)) == -1)
      error("couldn't open file %s", argv);
    copy(f1, 1);
  }

  return 0;
}


void error(char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  fprintf(stderr, "error ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  _exit(1);
}


void copy(int fd1, int fd2)
{
  int n;
  char buf[BUFSIZ];
  while ((n = read(fd1, buf, sizeof buf)) != 0) {
    if (n == -1)
      error("couldn't read file");
    write(fd2, buf, n);
  }
}
