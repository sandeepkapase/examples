#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


const char* USER_INPUT = "10";



int * fibonaaciArray(int n) {
  int *arr = malloc(sizeof(int)*(n+1));
  arr[0] = 0;
  arr[1] = 1;
  for (int i=2; i<=n ; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }
  return arr;
}

int fiboprint(int n) {
  int x=0, y=1;
  for (int i=0; i<n; i++) {
    printf("%3d", x);
    int tmp=y;
    y=x+y;
    x=tmp;
  }
  return 0;
}

int main(int argc, char*argv[]) {
  int n;
  sscanf(USER_INPUT, "%d", &n);
  int *fibarr = fibonaaciArray(10);
  for (int i=0; i<n; i++)
    printf("%3d", fibarr[i]);
  printf("\n");
  fiboprint(n);
  return 0;
}
