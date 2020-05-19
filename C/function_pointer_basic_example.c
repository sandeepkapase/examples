#include <stdio.h>

int someFunction(int x) {
  return x+1;
}

int main() {
  int (*funPtr) (int) = someFunction;
  //int (*funPtr) (int) = &someFunction; // Note & is optional
  printf("\nFunction call %d", someFunction(1));
  printf("\nFunction Pointer call 1 : %d", funPtr(1));
  printf("\nFunction Pointer call 2 : %d", (*funPtr)(1));
}
