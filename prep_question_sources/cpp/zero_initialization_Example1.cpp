// [[file:~/github/prep/cpp/Questions.org::c++ zero_initialization_Example1 example.][c++ zero_initialization_Example1 example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
struct foo {
  int x, y, z;
};

double x[3]; // zero-initialized to three 0.0's
int *y ; // zero-initialized to null pointer value
int main(int argc, char*argv[]) {
  foo f = foo(); // OR foo f{};
  cout << "\n" << f.x <<  f.y << f.z;
  int i{}; // zero initialized. otherwise random
  int arr[100]{}; // zero initialize. otherwise random
  int *ptr{}; // zero initialize. otherwise random
  char charr [10] = "";
  cout << "\nint val:" << i;
  cout << "\nint arr:" << arr[91];
  cout << "\nPointer:" << ptr;
  cout << "\nChar arr:" << charr;
  return 0;
}
// c++ zero_initialization_Example1 example. ends here
