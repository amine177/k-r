#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifdef PERMS
#undef PERMS
#endif

#ifdef BUFSIZ
#undef BUFSIZ
#endif

#define PERMS 0666
#define BUFSIZ 1024


int main(int argc, char *argv[])
{
  int f1, f2, n;
  char buf[BUFSIZ];

  if (argc != 3) {
    printf("Usage: cp from to\n");
    return(1);
  }
  if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
    printf("cp: can't open %s\n", argv[1]);
    return(-1);
  } 
  if ((f2 = creat(argv[2], PERMS)) == -1) {
    printf("cp: can't create %s, mode %03o\n",
        argv[2], PERMS);
    return(-1);
  }
  while((n = read(f1, buf, sizeof buf)) > 0)
    if (write(f2, buf, n) != n) {
      printf("cp: write error on file %s\n", argv[2]);
      return(-1);
    }

  return 0;
}
