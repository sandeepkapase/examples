// [[file:~/github/prep/cpp/Questions.org::pure virtual function example.][pure virtual function example.]]
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

class shape {
  virtual float area() = 0;
};
int main() {
  cout << "Hello world!";
  return 0;
}
// pure virtual function example. ends here
