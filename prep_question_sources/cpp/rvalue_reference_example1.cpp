#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






using namespace std;

int main() {
  int x;
  int &refx = x;
  // int &refi = 100; // This will give error as you can not create reference to rvalue.
  int &&refi = 100; // This is rvalue reference which allow us to create reference to rvalue.
  return 0;
}
