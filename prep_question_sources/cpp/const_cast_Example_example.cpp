// [[file:~/github/prep/cpp/Questions.org::const_cast examples][const_cast examples]]
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
class point {
private:
  int data;
public:
  point(int data=0): data(data) {}
  void printdata() { cout << "\ndata:" << data ; }
  int getdata() const { const_cast<point*>(this)->data = data+1; return data;}
};
int main() {
  point p;
  p.printdata();
  p.getdata();
  p.printdata();
  p.getdata();
  p.printdata();
  /* simple examples: Below examples are for simplycity. In reality we never change const values and results are unpredictable.
     const int i = 10;
     const int *j = &i;
     const int &k = i;
     // ERRORS
     *j = 111;
     k = 111;
     // TYPECAST FIX
     *const_cast<int *>(j) = 111;
     const_cast<int &>(k) = 111;
  */
  return 0;
}
// const_cast examples ends here
