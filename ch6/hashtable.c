#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "bufutilsparser.h"


struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

int getword(char *, int);
static struct nlist *install(char *, char *);
#define MAXWORD 100
int main(int argc, char **argv)
{

  char s[MAXWORD];
  char *name, *defn;

  while (getword(s, MAXWORD) != EOF) {
    if (strcmp(s, "#define") == 0) {
      getword(s, MAXWORD);
      if (isalpha(s[0])) {
        name = malloc(sizeof(strlen(s)));
        getword(s, MAXWORD);
        if (isalpha(s[0])) {
          defn = malloc(sizeof(strlen(s)));
          install(name, defn);
        }
        else {
          free(name);
          printf("invalid #define\n");
        }
      } else {
        printf("invalid #define\n");
      }
    }
  }
}

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



struct nlist *install(char *name, char *defn)
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


int getword(char *s, int n)
{
  int c;
  while ((c = getch()) == ' ')
    ;

  if (c != EOF && --n >= 0)
    *s++ = c;

  if (!isalpha(c) && c != '#') {
    *s = '\0';
    return c;
  }

  while ((isalpha(c = getch()) || c == '_') && --n > 0)
    *s++ = c;

  if (!isalpha(c))
    ungetch(c);
  *s = '\0';
  return s[0];
}

