#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 14

int inputArray[ARRAY_SIZE] = {3,6,36,32,32,121,66,24,26,371,661,6,4,8};
int size = ARRAY_SIZE;

int main() {
  //int inputArray[ARRAY_SIZE], size = 0;
  int currentProfit,lastProfit=0;

  /*do {
    scanf("%d", &inputArray[size++]);
    } while (inputArray[size-1] != -1);*/

  //size--;

  if (size < 2) {
    printf("%d",0);
    return -1;
  }

  for (int i=0,j=0; i<size; i=j+1) {
    for (j = i; j+1<size && inputArray[j] <= inputArray[j+1]; j++);
    if (j != i) {
      currentProfit = inputArray[j]-inputArray[i];
      if (lastProfit < currentProfit)
        lastProfit = currentProfit;
    }
  }

  printf("%d", lastProfit);
  return 0;
}
