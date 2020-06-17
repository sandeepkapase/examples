#include <stdio.h>
#include <unistd.h>
#include <pthread.h>






int refArray[11] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int fiboArray(int x) {
  if (refArray[x] != -1) return refArray[x];
  if (x<=1)
    return refArray[x] = x;

  return refArray[x] = fiboArray(x-1) + fiboArray(x-2);
}

int fibolast(int n) {
  if (n<=1)
    return n;
  return fibolast(n-1) + fibolast(n-2);
}

int main(int argc, char*argv[]) {
  fiboArray(10);
  for(int i=0; i<=10; i++)
    printf("%3d", refArray[i]);
  printf("\n%3d", fibolast(10));

  return 0;
}
