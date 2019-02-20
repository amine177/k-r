#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


void error(char *, ...);
void copy(int, int);


int main(int argc, char *argv[])
{
  int fd;

  if (argc == 1) {
    copy(0, 1);
    return 0;
  } else
    while (--argc > 0) {
      if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
        error("can't open file %s", *argv);
      else {
        copy(fd, 1);
        close(fd);
      }
  }
}


void copy(int src, int dst)
{
  int n;
  char buf[BUFSIZ];

  while ((n = read(src, buf, sizeof buf)) > 0)
    write(dst, buf, n);
}
