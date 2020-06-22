// [[file:~/github/prep/cpp/Questions.org::use virtul destructor to fix this problem][use virtul destructor to fix this problem]]
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
class b {
public:
  b() {
    cout<<"Constructing base \n";
  }
  // ~b() { //Problem
  virtual ~b() { // FIX
    cout<<"Destructing base \n";
  }
};
class d: public b {
public:
  d() {
    cout<<"Constructing derived \n";
  }
  ~d() {
    cout<<"Destructing derived \n";
  }
};

int main(void) {
  d *derived = new d();
  b *bptr = derived;
  delete bptr; // ==> this will call bptr->~b();
  //bptr->~b(); // without virtual this will also call base destructor only.
  return 0;
}
// use virtul destructor to fix this problem ends here
