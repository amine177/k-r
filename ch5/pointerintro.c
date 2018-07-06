#include <stdio.h>


int main(void)
{
  int x = 1, y = 2, z[10];
  int *ip; /* pointer to int */
  
  ip = &x; /* ip points to x */
  printf("ip: %x, x: %d, y: %d, z: %x\n", ip, x, y, z);
  y = *ip; /* y have the value pointed to by ip */
  printf("ip: %x, x: %d, y: %d, z: %x\n", ip, x, y, z);
  *ip = 0; /* x have 0 */
  printf("ip: %x, x: %d, y: %d, z: %x\n", ip, x, y, z);
  ip = &z[0];
  printf("ip: %x, x: %d, y: %d, z: %x\n", ip, x, y, z);
  
  return 0;
}
