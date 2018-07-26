#include <stdio.h>
#include <string.h>

struct point {
  int x;
  int y;
  char name[9];
};

struct point makepoint(int, int, char[]);

int main(void)
{
  struct point pt, pt1;
  pt.x = 5;
  pt.y = 10;
  strcpy(pt.name, "point");
  printf("%s: x: %d, y: %d\n", pt.name, pt.x, pt.y);
  pt1 = makepoint(pt.x, pt.y, "point1");
  printf("%s: x: %d, y: %d\n", pt1.name, pt1.x, pt1.y);
  return 0;
}


struct point makepoint(int x, int y, char name[])
{
  struct point temp;

  temp.x = x;
  temp.y = y;
  strncpy(temp.name, name, 9);
  return temp;
}
