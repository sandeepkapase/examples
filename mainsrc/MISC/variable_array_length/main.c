#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define MAX_STR_LEN 100

typedef struct fam {
  int a;
  char str[];
}fam;

void printvla(int *arr, int n) {
  for (int i=0; i<n; i++)
    printf("%d	", arr[i]);
}

int * vla(int n) { // variable length array
  int arr[n];

  int *ptr = arr;
  printf("\nSize of arr: %lu\n", sizeof(arr));

  for(int i=0; i<n; i++)
    arr[i] = i;
  //printvla(arr, n);
  //return arr; // segfault
  return ptr; // no segfault
}

int main() {
  int count = 10;
  int *ptr;


  ptr = vla(10); // difference in sizeof
  ptr = vla(20); // difference in sizeof
  return 0;
  for (int i=0; i<count; i++)
    printf("%d	", ptr[i]);
  return 0;
}
