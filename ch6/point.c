#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
struct point {
  int x;
  int y;
  char name[9];
};

struct rect {
  struct point p1;
  struct point p2;
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

struct point addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.p1.x && p.x < r.p2.x
      && p.y >= r.p1.y && p.y < r.p2.y;
}

struct rect canonicrect(struct rect r)
{
  struct rect temp;

  temp.p1.x = min(r.p1.x, r.p2.x);
  temp.p1.y = min(r.p1.y, r.p2.y);
  temp.p2.x = max(r.p1.x, r.p2.x);
  temp.p2.y = max(r.p1.y, r.p2.y);
  return temp;
}
