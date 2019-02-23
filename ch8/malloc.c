#include <stdlib.h>
#include <stdio.h>

typedef long Align;

union header {
  struct {
    union header *ptr;
    unsigned size;
  } s;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;
static Header *morecore_(unsigned);

void *malloc_(unsigned nbytes)
{
  Header *p, *prevp;
  unsigned nunits;

  nunits = (nbytes + sizeof(Header)-1)/sizeof(Header) + 1;
  if ((prevp = freep) == NULL) {
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
    if (p->s.size >= nunits) {
      if (p->s.size == nunits)
        prevp->s.ptr = p->s.ptr;
      else {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p+1);
    }
  }
}


#define NALLOC 1024

static Header *morecore_(unsigned nu)
{
  char *cp, *sbrk(int);
  Header *up;

  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *) -1)
    return NULL;
  up = (Header *) cp;
  up->s.size = nu;
  free((void *)(up + 1));
}

int main()
{
  char *s = (char *)malloc(8);
  printf("%x\n", s);
  printf("%d\n", sizeof(s));
}
