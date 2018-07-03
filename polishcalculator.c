#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

int getop(char[]);
int getch(void);
void ungetch(int c);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void clear();


int main(void)
{

  double op2;
  double op1;
  char s[MAXOP];
  int type;
  double d;
  double d1;
  // get operands until EOF is given and put them in s[]
  while ((type = getop(s)) != EOF) {
    switch(type) {
      // is the input a number ?
      case NUMBER:
        // push it
        push(atof(s));
        break;
      // else it is an operator, do the operation poping the number operands
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        op1 = pop();
        if (op1 < 0 || op2 < 0)
          printf("error: modulous of negative number\n");
        else
          push((int) op1 % (int)op2);
        break;
      case 'p':
        printf("PEEK: \t%.8g\n", peek());
        break;
      case '\n':
        //printf("\t%.8g\n", peek());
        break;
      case 'r':
        printf("RESULT: \t%.8g\n", pop());
        break;
      case 'c':
        printf("CLEARING...\n");
        clear();
        break;
      case 's':
        swap();
        break;
      default:
        printf("error: unkown command %s\n", s);
        break;
    }
  }
  return 0;
}


void clear(void)
{
  sp = 0;
}
void push(double f)
{
  if (sp < MAXVAL) {
    val[sp++] = f;
  }
  else
    printf("error: stack full, can't push %g\n", f);
}


double pop(void)
{
  if (sp > 0) {
    return val[--sp];
  }
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double peek(void)
{
  if (sp > 0)
    return val[sp - 1];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void swap(void)
{
  double tmp;
  if (sp > 1) {
    tmp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = tmp;
    printf("swap done\n");
  }
  else
    printf("error: stack doesn't have tow elements\n");
}

int getop(char s[])
{
  int i, c;
  //skip white spaces and tabs, save value otherwise
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
