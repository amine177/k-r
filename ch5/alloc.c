#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
  if (ALLOCSIZE + allocbuf - allocp >= n) {
    allocp += n;
    return allocp - n;
  }
  else
    return 0;
}

void afree(char *p)
{
  if  (p >= allocbuf && p < allocbuf + ALLOCSIZE && p < allocp)
    allocp = p;
  p = 0x0;
}
