#include <stdio.h>
#include <stdlib.h>
#include <mischelper/miscHelper.h>
#define MAX_VAL 100 // array can not have value greater than MAX_VAL
#define MIN_VAL -100 // array can not have value greater than MAX_VAL

void swap_meta(int arr[], int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int getMax(int arr[], int n) {
  int max = arr[n-1];
  while(--n>=0)
    if (max < arr[n])
      max = arr[n];
  return max;
}

// positive numbers only
void countingSorta(int arr[], int n) {
  int indexArr[MAX_VAL] = {0}, maxVal = MAX_VAL, index=0;

  while(--n >= 0)
    indexArr[arr[n]]++;

  while(--maxVal >= 0)
    while (indexArr[maxVal]-- > 0)
      arr[index++] = maxVal;
}

// negative number also
void countingSortb(int arr[], int n) {
  int indexArr[MAX_VAL-MIN_VAL] = {0}, maxVal = MAX_VAL-MIN_VAL, index=0;

  while(--n >= 0)
    indexArr[arr[n]-MIN_VAL]++;

  while(--maxVal >= 0)
    while (indexArr[maxVal]-- > 0)
      arr[index++] = maxVal+MIN_VAL;
}


/* problems:
Counting sort:
* linear time complexity.
* Good when data size is small.
* Bad for huge data (require huge memory/space)
* time complexity: n+k
*/
int main(int argc, char *argv[])
{
  int arr[10];
  int n = sizeof(arr)/sizeof(int);
  fillArrRandomPN(arr, n);
  printArr(arr, n);
  countingSortb(arr, n);
  printArr(arr,n);
  return 0;
}
