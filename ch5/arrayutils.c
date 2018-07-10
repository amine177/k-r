#include <string.h>

void qsortutil(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);
  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsortutil(v, left, last-1);
  qsortutil(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
  char *tmp;
  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}
