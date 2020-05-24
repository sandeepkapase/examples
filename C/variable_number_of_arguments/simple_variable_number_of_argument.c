#include <stdio.h>
#include <stdarg.h>
/* Example for variable number of arguments */

int sumof(int count, ...) {
  va_list arglist;
  int sum=0;

  va_start(arglist, count);
  for(int i=0; i<count; i++)
    sum+=va_arg(arglist, int);
  return sum;
}
int main(void){
  printf("\nsum:%d", sumof(1,1));
  printf("\nsum:%d", sumof(2,7,8));
  printf("\nsum:%d", sumof(3,7,8,9));
  printf("\nsum:%d", sumof(4,2,3,4,5));
}


