// [[file:~/github/prep/cpp/Questions.org::use shared_ptr_to_call_destructor of_derived_class][use shared_ptr_to_call_destructor of_derived_class]]
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
    ~b() { //Problem. If used with shared_ptr it gets fixed.
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
  shared_ptr<b> (new(d) );
  //shared_ptr<b> (newdd());
  //b *bptr = derived;
  //delete bptr; // ==> this will call bptr->~b();
  //bptr->~b(); // without virtual this will also call base destructor only.
  return 0;
}
// use shared_ptr_to_call_destructor of_derived_class ends here
