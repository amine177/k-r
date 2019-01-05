#include <fcntl.h>
#include <stdio.h>


int main(int argc, char **argv)
{
  int fd;

  if (argc != 2) {
    printf("Usage: open_test.o filename");
    return -1;
  }

  fd = open(*(argv+1), O_RDONLY, 0);

  printf("Opened: %s, with fd: %d\n", *(argv+1), fd);

  return 0;
}
