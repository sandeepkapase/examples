// [[file:~/github/prep/cpp/Questions.org::c++ object_to_manage_resources_example1 example.][c++ object_to_manage_resources_example1 example.]]
#include <map>
#include <mutex>
#include <list>
#include <deque>
#include <thread>
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>
#include <unistd.h>
#include <tuple>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>






using namespace std;
std::mutex  lck;
void somefunction(void) {
  lck.lock();
  cout << "\nlocked in fun";
  throw 1;
  lck.unlock();
  cout << "\nunlocked in fun";
}
int main(int argc, char*argv[]) {
  try {
    somefunction();
  } catch(...) {
    cout << "\nexcpetion handled";
  }
  cout << "\nTrying lock in main\n";
  lck.lock();
  cout << "\nlocked in main";
  lck.unlock();
  cout << "\nback to main execution";
  return 0;
}
// c++ object_to_manage_resources_example1 example. ends here
