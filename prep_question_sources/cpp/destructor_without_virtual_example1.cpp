// [[file:~/github/prep/cpp/Questions.org::c++ destructor_without_virtual_example1 example.][c++ destructor_without_virtual_example1 example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
class base {
public:
  base(){ cout << "\nbase constructor";}
  ~base(){ cout << "\nbase destructor";}
};
class derived:public base{
public:
  derived(){ cout << "\nderived constructor";}
  ~derived(){ cout << "\nderived destructor";}
};

int main(int argc, char*argv[]) {
  base *bptr = new(derived);
  delete bptr;

  return 0;
}
// c++ destructor_without_virtual_example1 example. ends here
