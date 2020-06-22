// [[file:~/github/prep/cpp/Questions.org::weak pointer to identify dangling reference][weak pointer to identify dangling reference]]
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
  std::shared_ptr<int>shptr(new int(10));
  std::weak_ptr<int> wptr = shptr;
  cout << "\nValue shptr: " << *shptr;
  cout << "\nRefCount shptr: " << shptr.use_count();
  if (wptr.lock())
    cout << "\nValid shptr: " << *wptr.lock();
  else
    cout << "\nInvalid reference: ";

  // After reset weak pointer will not return valid object reference.
  shptr.reset(new int(11));
  if (wptr.lock())
    cout << "\nValid shptr: " << *wptr.lock();
  else
    cout << "\nInvalid reference: ";
  return 0;
}
// weak pointer to identify dangling reference ends here
