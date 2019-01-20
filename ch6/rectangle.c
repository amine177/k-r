#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int, int);

void printpoint(struct point);

int main(void)
{

  struct rectangle rect = {{2, 2}, {3, 3}};
  struct point p1;

  printf("%d, %d, %d, %d\n", rect.pt1.x, rect.pt1.y, rect.pt2.x, rect.pt2.y);

  p1 = makepoint(3, 4);
  printpoint(p1);

  return 0;
}


void printpoint(struct point pt)
{
  printf("Point(%d, %d)\n", pt.x, pt.y);
}

struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;

  return temp;
}
