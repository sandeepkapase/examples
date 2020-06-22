// [[file:~/github/prep/cpp/Questions.org::const memeber function.][const memeber function.]]
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






/* const member function can not modify data member of class object */
using namespace std;

class point {
private:
  int x,y;
public:
  /* We can not do modification to data member in below function.
     Compiler will throw error if there is any modification to data member */
  int getPointX() const {
    //x++ ; // error here
    return x;}
};

point testfun(point x) {
  return x;
}
int main() {
  point c{}; // default constructor call
  return 0;
}
// const memeber function. ends here
