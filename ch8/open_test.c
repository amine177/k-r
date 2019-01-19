#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv)
{
  int fd;

  if (argc != 2) {
    write(1, "Usage: open_test.o file", 23);
    return -1;
  }

  fd = open(*(argv+1), O_RDONLY, 0);

  printf("Opened: %s, with fd: %d\n", *(argv+1), fd);

  return 0;
}
