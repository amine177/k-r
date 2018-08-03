#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};


#define HASHSIZE 101


static struct nlist *hashtab[HASHSIZE];


unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}


struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(np->name, s) == 0)
      return np;
  return NULL;
}



struct nlist *instal(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashvalue;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL
        || (np->defn = strdup(defn)) == NULL )
      return NULL;
    hashvalue = hash(np->name);
    np->next = hashtab[hashvalue];
    hashtab[hashvalue] = np;
  } else {
    free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
      return NULL;
    return np;
  }
}

void undef(char *name, char *defn)
{
  struct nlist *np, *prev = NULL;
  unsigned hashval;

  for (np = lookup(name); np != NULL; prev = np, np = np->next)
    if (strcmp(np->name, name) == 0)
      if (strcmp(np->defn, defn)) {
        free((void *) np->defn);
        free((void *) np->name);
        if (prev == NULL)
          hashtab[hash(name)] = np->next;
        else
          prev->next = np->next;
        free((void *) np);
        break;
      }

}
