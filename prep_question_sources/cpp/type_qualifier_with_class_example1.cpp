// [[file:~/github/prep/cpp/Questions.org::c++ type_qualifier__with_classexample1.cpp example.][c++ type_qualifier__with_classexample1.cpp example.]]
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
  void func() &                { cout << "\n1 ref lvalue";}                         // 1
  void func() &&               { cout << "\n2 ref rvalue"; }                        // 2
  void func() const&           { cout << "\n3 const ref lvalue"; }                  // 3
  void func() const&&          { cout << "\n4 const ref rvalue"; }                  // 4
  void func() volatile&        { cout << "\n5 volatile ref lvalue"; }               // 5
  void func() volatile&&       { cout << "\n6 volatile ref rvalue"; }               // 6
  void func() const volatile&  { cout << "\n7 const volatile ref lvalue"; }         // 7
  void func() const volatile&& { cout << "\n8 volatile const ref rvalue"; }         // 8
};
int main(int argc, char*argv[]) {
  // CLASS METHOD
  testclass a; a.func();                 // 1
  move(a).func();                        // 2
  testclass().func();                    // 2
  testclass const b; b.func();           // 3
  move(b).func();                        // 4
  testclass volatile c; c.func();        // 5
  move(c).func();                        // 6
  testclass const volatile d; d.func();  // 7
  move(d).func();                        // 8
  return 0;
}
// c++ type_qualifier__with_classexample1.cpp example. ends here
