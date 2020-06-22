// [[file:~/github/prep/cpp/Questions.org::auto_ptr_example][auto_ptr_example]]
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
int main() {
  std::auto_ptr<int> p(new int(11));
  std::cout << "\nValue of p: " << *p << std::endl;
  std::auto_ptr<int> q(p);
  std::cout << "\nValue of q: " << *q << std::endl;
  if (p.get() == nullptr)
    std::cout << "\np is now empty";
  return 0;
}
// auto_ptr_example ends here
