// [[file:~/github/prep/cpp/Questions.org::abstract class example.][abstract class example.]]
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
class shape {
public:
  virtual float area() = 0;
};

class square: public shape {
private:
  float side;
public:
  square(float s): side(s) {}
  float area() {
    return side*side;
  }
};
int main() {
  square s(3);
  cout << "Square area: " << s.area();
  return 0;
}
// abstract class example. ends here
