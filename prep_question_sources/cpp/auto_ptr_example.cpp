#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
#include <memory> // smart pointers.

int main() {
  std::auto_ptr<int> p(new int(11));
  std::cout << "\nValue of p: " << *p << std::endl;
  std::auto_ptr<int> q(p);
  std::cout << "\nValue of q: " << *q << std::endl;
  if (p.get() == nullptr)
    std::cout << "\np is now empty";
  return 0;
}
