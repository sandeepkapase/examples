// [[file:~/github/prep/cpp/Questions.org::c++ nothrow_Example1 example.][c++ nothrow_Example1 example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
int main(int argc, char*argv[]) {
  long x = numeric_limits<unsigned long>::max();
  int *p = new(std::nothrow) int[x];
  if (p== nullptr) {
    cout << "\nMemory allocation problem. Exiting...";
    exit(EXIT_FAILURE);
  }
  return 0;
}
// c++ nothrow_Example1 example. ends here
