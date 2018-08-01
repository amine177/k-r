/*Exercise 6-2. Write a program that reads a C program and prints in alphabetical order each
 * group of variable names that are identical in the first 6 characters, but different somewhere
 * thereafter. Don't count words within strings and comments. Make 6 a parameter that can be set
 * from the command line.
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {      /* the tree node: */
    char *word;           /* points to the text */
    int match;            /* number of occurrences */
    struct tnode *left;   /* left child */
    struct tnode *right;  /* right child */
};

struct tnode *addtree(struct tnode *, char *, int, int);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
int main(int argc, char **argv)
{
      struct tnode *root;
      char word[MAXWORD];
  int n = 6;
    
  if (argc == 3)
    if (strcmp("-n", argv[1]) == 0)
      n = atoi(argv[2]);
    else {
          printf("error\n");
          return 1;
        } 
  root = NULL;
  while (getword(word, MAXWORD) != EOF) 
    if (isalpha(word[0])) 
      root = addtree(root, word, 0, n);
  treeprint(root);
      return 0;
}

struct tnode *talloc(void);
char *mstrdup(char *s);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int found, int n)
{
      int cond;
    
  if (p == NULL) {  /* a new word has arrived */
            p = talloc(); /* make a new node */
            p->word = mstrdup(w);
            p->match = (found) ? 1 : 0;
            p->left = p->right = NULL;  
    } 
      else if ((cond = strcmp(w, p->word)) < 0) {   
          if (strncmp(w, p->word, n) == 0) 
            found = p->match = 1;   
          p->left = addtree(p->left, w, found, n);  
        }   
  else if (cond > 0) {        
      if (strncmp(w, p->word, n) == 0) 
        found = p->match = 1;   
      p->right = addtree(p->right, w, found, n);
    }
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  if (p != NULL) {
            treeprint(p->left);
      if (p->match)
          printf("%4d %s\n", p->match, p->word);
            treeprint(p->right);
    }
}

/* getword: get next word or character from input */
#define IN 1
#define OUT 0
int getword (char *word, int lim)
{
  int c, d, getch(void), comment, string, directive;
  void ungetch(int);
  char *w = word;

  comment = string = directive = OUT; 
  while (isspace(c = getch()))
    ; 
  if (c == '/') {
      if ((d = getch()) == '*')
        comment = IN; 
      else
        ungetch(d);
    }
  else if (c == '\"')
    string = IN;
  else if (c == '#') {
      if ((d = getch()) != '\'') 
        directive = IN;
      ungetch(d);
    }
  else if (c == '\\') /* salta il carattere \ */ 
    c = getch();
  if (comment == OUT && string == OUT && directive == OUT) {  
      if (c != EOF) 
        *w++ = c;
      if (!isalnum(c) && c != '_') {
            *w = '\0';
            return c;
          }   
      for (; --lim > 0; w++) 
        if (!isalnum(*w = getch()) && *w != '_') {  
                ungetch(*w);
                break;
              }
      *w = '\0';  //printf("w=%s\n", word);
      return word[0];
    }
  else if (comment == IN) { /* ignora i commenti */
      *w++ = c;
      *w++ = d;   
      while ((*w++ = c = getch())) {
            if (c == '*') {
                    if ((c = getch()) == '/') {
                              *w++ = c;         
                              comment = OUT;
                              break;
                            }     
                    else 
                      ungetch(c);
                  }
          }
      *w = '\0';  //printf("w=%s\n", word);
    }
  else if (string == IN) {  /* ignora le stringe */
      *w++ = c;   
      while ((*w++ = getch()) != '\"')    
        if (*w == '\\') 
          *w++ = getch(); 
      string = OUT; 
      *w = '\0';  //printf("w=%s\n", word);
    }
  else if (directive == IN) {
      *w++ = c;
      while ((*w++ = c = getch()) != '\n')
        if (c == '\\')
          *w++ = getch();
      directive = OUT;
      *w = '\0';  //printf("len=%d\nw=%s\n", strlen(word), word);
    }
  return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer per ungetch */
int bufp = 0;   /* prossima posizione libera per buf */

int getch(void)   /* legge un carattere, eventualmente accantonato prima */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* accantona un carattere letto */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: troppi caratteri \n");
  else {
      buf[bufp++] = c;
    } 
}

#include <stdlib.h>
/* talloc: make a tnode */
struct tnode *talloc(void)
{
      return malloc(sizeof(struct tnode));
}

char *mstrdup(char *s)   /* make a duplicate of s */
{
      char *p;
      
  p = malloc(strlen(s)+1); /* +1 for '\0' */
      if (p != NULL)
          strcpy(p, s);
      return p;
}
