#include <stdio.h>
static int stativar; // This static variable definition should come
                     // first before its extern declaration
extern int stativar;
extern int global_var=100;
int addition(int a, int b) {
  printf("\nFunction call from compilation unit one");
  return a+b+global_var;
}
