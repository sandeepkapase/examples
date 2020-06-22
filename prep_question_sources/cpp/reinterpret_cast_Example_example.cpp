// [[file:~/github/prep/cpp/Questions.org::reinterpret_cast examples][reinterpret_cast examples]]
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
class A {};
class B:public A {};
class Other {};
int main() {
  int *iptr = new int(65);
  // char *cptr = static_cast<char *>(iptr); // Error Here: completely different type
  char *cptr = reinterpret_cast<char *>(iptr);
  cout << "\nint val: " << *iptr;
  cout << "\nchar val: " << *cptr;
  return 0;
}
// reinterpret_cast examples ends here
