#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<fun_ptr_example_1.h>

/* Example of function pointer */


typedef int (*funptr)(int, int);
int main()
{
  funptr ptr[] = { add, substract, divide, multiply };
  int i = sizeof(ptr)/sizeof(funptr);

  while ( --i >= 0)
    printf("\nIndex: %d Operation Value: %d", i, ptr[i](9,7));

  return 0;
}
