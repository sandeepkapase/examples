// [[file:~/github/prep/cpp/Questions.org::c++ const_method_overloading_in_class example.][c++ const_method_overloading_in_class example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
class someclass {
public:
  void somefunc(int *p ) { cout << "\nnon const call";}
  void somefunc(int const *p ) { cout << "\nconst call";}
  void somefunc(int const *p ) const { cout << "\nunmutable const call";}
};
int main(int argc, char*argv[]) {
  int *p = new int(1);
  int const *q = new int(1);
  someclass c;
  c.somefunc(p);
  c.somefunc(q);
  const someclass cc;
  cc.somefunc(q);
  return 0;
}
// c++ const_method_overloading_in_class example. ends here
