/* const member function can not modify data member of class object */
using namespace std;
#include <iostream>
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
