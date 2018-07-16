#include <stdio.h>
#include "calc.h"
#include "stack.h"
#include "conversions.h"

#define MAXOP 100

int main(int argc, char *argv[])
{

  double op2;
  double op1;
  char s[MAXOP];
  int type;
  double d;
  double d1;
  double x;
  
  if (argc == 1) {
    printf("Usage: expr 5 2 * 5 +\n");
    return -1;
  }
  printf("r: result, p: peek, s: swap\n");
  // get operands until EOF is given and put them in s[]
  while ((type = getop(s, argv, argc)) != EOF) {
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
