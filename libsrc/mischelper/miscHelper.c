#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fillSequentialArray(int arr[], int size) {
    for (int i=1; i <size; i++)
        arr[i] = i;
}
