#include <stdio.h>
#define MYSIZEOF(type) (char *)(&type+1) - (char*)(&type)

int main() {
  int w ;
  float x;
  double y;
  char z[100];
  printf("\nsize of x:%d", MYSIZEOF(w));
  printf("\nsize of x:%d", MYSIZEOF(x));
  printf("\nsize of x:%d", MYSIZEOF(y));
  printf("\nsize of x:%d", MYSIZEOF(z));
}
