#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXCHARS MAXLINES * 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int lines, char *line);
void writelines(char *lineptr[], int nlines);
int getline_(char*, int);
int rfstrcmp(char *s1, char *s2);
int fstrcmp(char *s1, char *s2);

void qsort_(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int rnumcmp(char *, char *);
int rstrcmp(char *, char *);

int main(int argc, char *argv[])
{
  int nlines, i = 0, c;
  int numeric = 0, reverse = 0, fold = 0;
  char *s = malloc(MAXCHARS);
  while (--argc)
    if ((*++argv)[0] == '-')
      while (c = (*argv)[++i])
        switch (c) {
          case 'r':
            reverse = 1;
            break;
          case 'n':
            numeric = 1;
            break;
          case 'f':
            fold = 1;
            break;
          default:
            printf("Unkown argument: -%c\n", c);
            exit(1);
            break;
        }
  printf("reverse: %d, numeric: %d, fold: %d\n", reverse, numeric, fold);
  if ((nlines = readlines(lineptr, MAXLINES, s)) >= 0) {
    printf("\n***sorting***\n");
    qsort_((void **) lineptr, 0, nlines-1,
        (int (*)(void*, void*)) (
          numeric ?
            reverse ? rnumcmp: numcmp :
            reverse ? 
              fold ? rfstrcmp: rstrcmp :
              fold ? fstrcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  }
  else {
    printf("input too big to sort\n");
    return 1;
  }
}


void qsort_(void *v[], int left, int right, int (*comp) (void*, void*))
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)
    return;
  swap(v, left, (left+right) / 2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0 && i >= (left+right) / 2)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort_(v, left, last-1, comp);
  qsort_(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int rfstrcmp(char *s1, char *s2) {
  int i = 0;
  while (*(s1+i) == *(s2+i) |
      abs(*(s1+i) - *(s2+i)) == abs(('a' - 'A')))
    i++;
  if (!*(s1+i))
    return 0;
  if (*(s1+i) > *(s2+i))
    return -1;
  return 1;
}

int fstrcmp(char *s1, char *s2) {
  return -rfstrcmp(s1, s2);
}
int numcmp(char *s1, char *s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int rnumcmp(char *s1, char *s2)
{
  return -numcmp(s1, s2);
}

int rstrcmp(char *s1, char *s2)
{
  return -strcmp(s1, s2);
}

char buffer[MAXCHARS];
int readlines(char *lineptr[], int linenbr, char *line)
{
  int n, total = 0, i = 0;
  while((n = getline_(line, MAXCHARS)) && i < linenbr) {
    strcpy(buffer+total, line);
    lineptr[i++] = buffer+total;
    total += (n+1);
  }
  return i;
}


void writelines(char *lineptr[], int linenbr)
{
  int i = 0;
  while (i < linenbr)
    printf("%s", lineptr[i++]);
}
int getline_(char *s, int linelen)
{
  int i = 0, c;
  while((c = getchar()) != EOF && (*(s+i++) = c) != '\n' && --linelen)
    ;
  if (c == EOF && i > 0)
    *(s+i++) = '\n';
  *(s+i) = '\0';
  return i;
}
