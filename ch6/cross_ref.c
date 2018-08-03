#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "bufutilsparser.h"

#define MAXWORD 100
#define MAXLINES 1000

int getword(char *, int);
struct node *addtolist(struct node *, char *, int);
void printlist(struct node *);
void reverselist(struct node **);

struct node {
  int lines[MAXLINES];
  int index;
  char *word;
  int count;
  struct node *next;
};

int main()
{
  char s[MAXWORD];
  struct node *root = NULL;
  int line = 1;
  while (getword(s, MAXWORD) != EOF)
    if (s[0] == '\n')
      line++;
    else
     root = addtolist(root, s, line);
  printlist(root);
  printf("reversing...\n");
  reverselist(&root);
  printlist(root);

  return 0;
}


int getword(char *s, int n)
{
  int c;

  while ((c = getch()) == ' ')
    ;

  if (c != EOF)
    *s++ = c;
  if (!isalpha(c) && c != '_' && --n) {
    *s = '\0';
    return c;
  }

  while ((isalnum((*s++ = c = getch())) || c == '_') && --n)
    ;

  if (!isalpha(c))
    ungetch(c);
  *--s = '\0';
  return s[0];
}

struct node *addtolist(struct node *root, char *word, int line)
{
  int cond;

  if (root == NULL) {
    root = (struct node *) malloc(sizeof(struct node));
    root->count = 1;
    root->index = 0;
    root->lines[root->index++] = line;
    root->word = (char *) malloc(sizeof(strlen(word)));
    strcpy(root->word, word);
    root->next = NULL;
  } else if ((cond = strcmp(word, root->word)) == 0) {
    root->count++;
    root->lines[root->index++] = line;
  } else
    root->next = addtolist(root->next, word, line);
  return root;
}

void printlist(struct node *root)
{
  if (root != NULL) {
    printf("%d: ", root->count);
    for (int i = 0; i < root->index; i++) {
      printf("%d", root->lines[i]);
      if (i != root->index - 1)
        printf(", ");
      else printf(" ");
    }
    printf("%s\n", root->word);
    printlist(root->next);
  }
}

void reverselist(struct node **root)
{
  struct node *first, *rest;

  if (root == NULL)
    return;

  first = *root;
  rest = first->next;

  if (rest == NULL)
    return;

  reverselist(&rest);

  first->next->next = first;
  first->next = NULL;

  *root = rest;
}
