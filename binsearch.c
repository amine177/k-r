#include <stdio.h>


int binsearch(int, int[], int);

int main(void)
{
  int v[4] = {1, 2, 5, 10};
  int n = 5;
  printf("Searching for %d in v...\n", n);
  int r = binsearch(n, v, 4);
  if (r != -1)
    printf("Found at %d\n", r);
  else
    printf("Not found!");

}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high && x != v[mid = (low + high) / 2])
  {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return (x == v[mid] ?  mid: -1);
}
