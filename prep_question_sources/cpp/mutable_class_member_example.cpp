// [[file:~/github/prep/cpp/Questions.org::mutable data member][mutable data member]]
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
  mutable int accessCount;
public:
  point(int data): data(data), accessCount(0) {}
  int getData () const { accessCount++; return data; }
};
int main() {
  point p(10);
  cout << "\nData: " << p.getData();
  cout << "\nData: " << p.getData();
  return 0;
}
// mutable data member ends here
