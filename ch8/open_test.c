#include <fcntl.h>
#include <unistd.h>


int main(void)
{
  int fd;

  fd = open("open_test.c", O_RDONLY, 0);

  return 0;
}
