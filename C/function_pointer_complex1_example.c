#include <stdio.h>

// MAKE USE TYPEDEF TO AVOID MULTIPLE LEVEL OF POINTER REFERENCING.

typedef void (*fPtrAccptVoidReturnInt)(int);
// "function pointer that accept function pointer" that points to function accepting int and returning void
typedef void (*funcAcceptFptrPtr)(fPtrAccptVoidReturnInt x);

void basicFunction(int x) {
  printf("\nBasic Function:%d", x);
  return;
}

void funcAcceptFptr(fPtrAccptVoidReturnInt x) {
  printf("\nFunction Parameters: Function pointer that points to function accepting int and returning void");
  x(100);
  return;
}


int main() {
  fPtrAccptVoidReturnInt basicFPtr = basicFunction;
  funcAcceptFptrPtr fptrfptr = funcAcceptFptr;
  fptrfptr(basicFPtr);
  //printf("\nFunction Pointer call 2 : %d", (*funPtr)(1));
}
