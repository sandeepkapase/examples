#include <iostream>
#include <unistd.h>






  using namespace std;
  #include <iostream>
template <typename T>
  void func (const T &&ref) { // const is best practise and not mandatory.
    cout << "\nCall by lvalue reference " << ref;
  }
  void func (const int ref) { // const is best practise and not mandatory.
    cout << "\nCallX by lvalue reference " << ref;
  }
  int main() {
    int x = 0;
    func(x); // lvalue reference
    func(&x); // lvalue reference
    func(0); // rvalue reference
    func(move(x)); // lvalue reference
    func(static_cast<int&&>(x)); // lvalue reference
    return 0;
  }
