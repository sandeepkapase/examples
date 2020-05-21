#include <stdio.h>

#ifdef RENAME_SUM
int sumu2(int a, int b) {
#else
int sum(int a, int b) {
#endif
  return a+b;
}
