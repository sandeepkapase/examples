// [[file:~/github/prep/cpp/Questions.org::c++ type_qualifier_with_function_example1.cpp example.][c++ type_qualifier_with_function_example1.cpp example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
void func(int & i)                 { cout << "\n1 int ref fun"; }
void func(const int & i)           { cout << "\n2 const int ref fun"; }
void func(volatile int & i)        { cout << "\n3 volatile ref lvalue"; }
void func(const volatile int & i)  { cout << "\n4 const volatile const ref lvalue"; }
void func(int && i)                { cout << "\n5 int ref rvalue fun"; }
void func(const int && i)          { cout << "\n6 const int ref rvalue fun"; }
void func(volatile int && i)       { cout << "\n7 volatile int ref rvalue fun"; }
void func(const volatile int && i) { cout << "\n8 const volatile const ref rvalue fun"; }

int main(int argc, char*argv[]) {
  // FUNCTION
  int i1=100; func (i1);                      // 1 reference
  const int i2=100; func(i2);                 // 2 const reference
  volatile int i3=100; func(i3);              // 3 volatile reference
  volatile const int i4=100; func(i4);        // 4 volatile const reference.
  func(100);                                  // 5 rvalue reference
  const int i5=100; func(move(i5));           // 6 const rvalue reference
  volatile int i6=100; func(move(i6));        // 7 volatile rvalue reference
  volatile const int i7=100; func(move(i7));  // 8 volatile const reference.
  return 0;
}
// c++ type_qualifier_with_function_example1.cpp example. ends here
