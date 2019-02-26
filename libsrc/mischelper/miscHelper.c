#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MOD_VAL 100

void fillSequentialArray(int arr[], int size) {
    for (int i=1; i <size; i++)
        arr[i] = i;
}

/* Fill array with uniq random number below MOD_VAL */
void fillArrUniqRandom(int arr[], int n) {
  srand(time(NULL));
  int base = rand() % MOD_VAL;
  int x,y,tmp;
  // sequential fill
  for (int i=0; i<n; i++) {
    arr[i] = base+i;
  }
  // randomize
  for (int i=0; i<n; i++) {
    x = rand() % n;
    y = rand() % n;
    if (x!=y) {
      tmp = arr[x];
      arr[x] = arr[y];
      arr[y] = tmp;
    }
  }
}

void printArr(int arr[], int n) {
  printf("\n");
  for (int i=0; i<n; i++) {
    printf("%d ", arr[i] );
   }
  printf("\n");
}
