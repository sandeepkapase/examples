// [[file:~/github/prep/cpp/Questions.org::unique pointer example][unique pointer example]]
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
void foo(int* p)
{
  std::cout << *p << std::endl;
}
int main() {
  std::unique_ptr<int> p(new int(40));
  int *ptr = p.get();
  std::cout << "\nptr begin" << *ptr << std::endl;
  p.reset(); // it will delete the associated raw pointer and make unique_ptr<> object empty
  std::cout << "\nptr begin" << *ptr << std::endl;

  std::unique_ptr<int> p1(new int(42));
  std::unique_ptr<int> p2 = std::move(p1); // transfer ownership
  std::unique_ptr<int> p3,p4;
  // std::unique_ptr<int> p5 = p1; // compiler error:  use of deleted function.
  // std::unique_ptr<int> p5(p1); //  compiler error:  use of deleted function.
  p3 = std::move(p2);
  p2 = std::move(p3);
  p4 = std::make_unique<int>(199);
  // = std::move(p1); // transfer ownership
  ///std::unique_ptr<int> p3(std::move(p2)); // transfer ownership

  if(p1) {
    foo(p1.get());
    std::cout << "\nP1: " << *p1.get();
  }

  (*p2)++;

  std::cout << "\nptr mid" << *ptr << std::endl;
  if(p2) {
    (*p2.get())++;
    foo(p2.get());
    std::cout << "\nP2: " << *p2.get();
  }
  p2.release();
  p2.reset();
  p1.reset();
  p3.reset();
  std::cout << "\nptr end" << *ptr << std::endl;
  return 0;
}
// unique pointer example ends here
