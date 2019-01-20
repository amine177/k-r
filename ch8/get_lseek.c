#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


void error(char *, ...);
int chararrtoi(char[], int);


int main(int argc, char *argv[])
{
  int fd1, offset, nbytes;
  char buf[1024];

  if (argc != 4)
    error("usage: get_lseek.o filename offset nbytes");

  if ((fd1 = open(*++argv, O_RDONLY)) == -1)
    error("couldn't open %s for reading", *argv);
  offset = chararrtoi(*++argv, strlen(*argv)+1);
  nbytes = chararrtoi(*(++argv), strlen(*argv)+1);
  printf("offset: %d, nbytes: %d\n", offset, nbytes);

  if (nbytes >= 1024)
    error("can't read %d bytes\n", nbytes);

  if (lseek(fd1, (long)offset, 0) >= 0) {
    read(fd1, buf, nbytes-1);
    buf[nbytes] = '\0';
    printf("read: %s\n", buf);
  } else {
    return -1;
  }

  return 0;

}


void error(char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  fprintf(stderr, "error: ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}


int chararrtoi(char a[], int l)
{
  int i, n;

  printf("length: %d\n", l);
  if (!(a[0] >= '0' && a[0] <= '9'))
    error("not an integer");
  n = 0;
  for (i = 0; i < l; i++) {
    printf("%c*\n", a[i]);
    if (a[i] >= '0' && a[i] <= '9')
      n = 10 * n + a[i] - '0';
    else
      break;
  }

  return n;
}
