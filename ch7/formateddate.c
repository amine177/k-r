#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int day, month, year;
  char **line = malloc(1);
  *line = malloc(30);
  char *monthname = malloc(10);
  size_t size = sizeof(line);

  while (getline(line, &size, stdin) > 0) {
    if (sscanf(*line, "%d %10s %d", &day, monthname, &year) == 3)
      printf("your date is: %s\n", *line);
    else if (sscanf(*line, "%d/%10s/%d", &day, monthname, &year) == 3)
      printf("your date is: %s\n", *line);
    else
      printf("invalid date: %s\n", *line);
  }
}
