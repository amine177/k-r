#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "bufutilsparser.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int error = 0;

int main(int argc, char *argv[])
{
  if (argc == 2)
    if (*(*(++argv)+1) == 'u') {
      int type, ptr = 0;
      char p[100];
      char temp[MAXTOKEN];
      
       while (gettoken() != EOF) {
         strcpy(out, token);
         while ((type = gettoken()) != '\n')
           if (type == PARENS || type == BRACKETS)
             strcat(out, token);
           else if (type == '*') {
             p[ptr++] = '*';
             while ((type = gettoken()) == '*' || type == ' ' ) {
               if (type == '*')
                 if (ptr < 100)
                   p[ptr++] = '*';
                 else
                   break;
             }
             p[ptr]='\0';
             ptr = 0;
             sprintf(temp, "(%s%s)", p,out);
             strcpy(out, temp);
         } else if (type == NAME) {
             sprintf(temp, "%s %s", token, out);
             strcpy(out, temp);
         } else
           printf("invalid input at %s\n", token);
         printf("%s\n", out);
       } 
    }
    else
      while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n' || error) {
          printf("syntax error, tokentype: %c\n", tokentype);
          if (tokentype != '\n')
            while(gettoken()!='\n')
              ;
          if (error)
            error = 0;
          continue;
        }

        printf("%s: %s %s\n", name, out, datatype);
      }
  return 0;
}
void dcl(void)
{
  int ns;

  for (ns = 0; gettoken() == '*';)
    ns++;
  dirdcl();
  while (ns-- > 0)
    strcat(out, " pointer to");
}

void dirdcl(void)
{
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (tokentype == NAME)
    strcpy(name, token);
  else {
    printf("error: expected name or (dcl)\n");
    error = 1;
    return;
  }
  while ((type=gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

int gettoken(void)
{
  int c;
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
      for (*p++ = c; (*p++ = getch()) != ']';)
        ;
      *p = '\0';
      return tokentype = BRACKETS;
    } else if (isalpha(c)) {
      for (*p++ = c; isalnum(c = getch());)
        *p++ = c;
      *p = '\0';
      ungetch(c);
      return tokentype = NAME;
    } else
      return tokentype = c;
}
