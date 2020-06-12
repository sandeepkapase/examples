#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
#include <memory>
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
