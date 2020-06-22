// [[file:~/github/prep/cpp/Questions.org::c++ cv_type_qualifier_polymorphism_example2.cpp example.][c++ cv_type_qualifier_polymorphism_example2.cpp example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
class testclass {
public:
  //void func()                {} // we can not overload with and without ref qualifier at same time.
  // In below example, we can not use non ref variant for have polymorphism
  void func() { cout << "\nNormal object";}
  void func() const { cout << "\nConst object";}
  void func() volatile { cout << "\nvolatile object";}
  void func() const volatile { cout << "\nConst volatile object";}
};
int main(int argc, char*argv[]) {
  testclass a; a.func();
  testclass const b; b.func();
  testclass volatile c; c.func();
  testclass const volatile d; d.func();
  return 0;
}
// c++ cv_type_qualifier_polymorphism_example2.cpp example. ends here
