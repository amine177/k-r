#include <fcntl.h>
#include <stdio.h>


int main(int argc, char **argv)
{
  int fd;

  if (argc != 2) {
    printf("Usage: creat_test filename\n");
    return -1;
  }

  ;

  if ((fd = creat(*(argv+1), 0666)) == -1)
    printf("failed to create %s\n", *(argv+1));
  else
    printf("%s created!\n", *(argv+1));

  return 0;
}
