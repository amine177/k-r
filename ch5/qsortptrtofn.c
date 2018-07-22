#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXCHARS MAXLINES * 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int lines, char *line);
void writelines(char *lineptr[], int nlines);
int getline_(char*, int);

void qsort_(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0;
  char *s = malloc(MAXCHARS);
  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES, s)) >= 0) {
    printf("\n***sorting***\n");
    qsort_((void **) lineptr, 0, nlines-1,
        (int (*)(void*, void*)) (numeric ? numcmp : strcmp));
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
