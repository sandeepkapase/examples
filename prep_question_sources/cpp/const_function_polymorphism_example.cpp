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

void somefunc(char *ptr) {std::cout << "\nnon constant version call"; }
void somefunc(char const *ptr) {std::cout << "\nCONSTANT version call";}
void somefuncint(int &ptr) {std::cout << "\nnon constant reference version call"; }
void somefuncint(int const &ptr) {std::cout << "\nCONSTANT reference version call";}

int main() {
  char *ptr = "kapse";
  const char *ptr1 = "kapse";
  somefunc(ptr);
  somefunc(ptr1);

  int x = 11;
  int &y = x;
  const int &z = x;
  somefuncint(y);
  somefuncint(z);
  return 0;
}
