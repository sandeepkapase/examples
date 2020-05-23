#include <stdio.h>
extern int staticvar;
int sum(int a, int b) {
  extern int global_var;
  printf("\nFunction call from compilation unit two");
  printf("\nstatic var from another unit: %d", staticvar);
  return a+b+global_var;
}
