#include <stdio.h>
#include "bufutilsparser.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
  char *value;
  int count;
  struct tnode *right;
  struct tnode *left;
};


struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void treeprint(struct tnode *, int);

int main(int argc, char **argv)
{
  char word[MAXWORD];
  struct tnode *root = NULL;
  while(getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);

  treeprint(root, 0);

  return 0;
}

int getword(char *s, int n)
{
  int c, i = 0;
  while (isspace(c = getch()))
    ;

  if (c != EOF)
    s[i++] = c;
  if (!isalpha(c) && c != '_' && c != '-') {
    s[i] = '\0';
    if (c == EOF)
      return c;
    else
      return i;
  }

  while(isalnum(c = getch()) || c == '_' || c == '-' && --n > 0)
    s[i++] = c;
  if (!isalpha(c))
    ungetch(c);
  s[i] = '\0';

  return i;
}

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *root, char *word)
{
  int cmp;

  if (root == NULL) {
    root = talloc();
    root->value = (char *) malloc(strlen(word)+1);
    strcpy(root->value, word);
    root->count = 1;
    root->right = root->left = NULL;
  } else {
    cmp = strcmp(word, root->value);
    if (cmp < 0)
      root->left = addtree(root->left, word);
    else if (cmp > 0)
      root->right = addtree(root->right, word);
    else
      root->count++;
  }
  return root;
}

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof( struct tnode));
}


void treeprint(struct tnode *p, int indent)
{
  int i;
  if (p != NULL) {
    for (i = 0; i < indent; i++)
      printf("\t");
    printf("%4d %s\n", p->count, p->value);
    treeprint(p->left, indent+1);
    treeprint(p->right, indent+1);
  }
}
