#include <iostream>
#include <vector>

#define ARRAY_SIZE 14


int main() {
    std::vector <int> inputArray = {3,6,36,32,32,121,66,24,26,371,661,6,4,8};
    //std::vector <int> inputArray;
    int currentProfit=0,lastProfit=0;
    int input,size,i,j;

    /*  while (std::cin >> input && input != -1) {
        inputArray.push_back(input);
    }*/
    
    size = inputArray.size();
    if (size < 2) {
        return -1;
    }

    for (i=0; i<size; i=j+1) {
    for (j = i; j+1 < size && inputArray[j] <= inputArray[j+1]; j++);
    if (j != i) {
        currentProfit = inputArray[j]-inputArray[i];
        if (lastProfit < currentProfit)
            lastProfit = currentProfit;
    }
  }

  std::cout << lastProfit;
  return 0;
}
