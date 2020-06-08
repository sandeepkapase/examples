#include <stdio.h>
#include <stdlib.h>
#include <mischelper/miscHelper.h>

void swap_meta(int arr[], int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int heapify(int arr[], int n, int i) {
  int l = i*2+1;
  int r = i*2+2;
  int largest = i;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (i != largest) {
    swap_meta(arr, i, largest);
    heapify(arr, n, largest);
  }
  return 0;
}

int heapSort(int arr[], int n) {
  for (int i=n/2-1; i>=0; i--) {
    heapify(arr, n, i);
  }
  for (int i=1; i<n; i++) {
    heapify(arr+i, n-i,0);
  }
  return 0;
}

/* problems: 
Find first K max/min elements
time complexity: n+k(logn)
*/
int main(int argc, char *argv[])
{
  int arr[30]; // = {111, 23, 45, 89, 21, 45, 234, 67 };
  int n = sizeof(arr)/sizeof(int);
  fillArrUniqRandom(arr, n);
  printArr(arr, n);
  heapSort(arr, n);
  printArr(arr,n);
  return 0;

  for (int i=n/2-1; i>=0 ; i--) {
    heapify(arr, n, i);
  }
  printArr(arr, n);
  return 0;
  
  for (int i=1; i<5 ; i++) {
    heapify(arr+i, n-i, 0);
    printArr(arr, n);
    //scanf("%d", &readvar);
  }
  return 0;
}
