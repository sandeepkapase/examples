/* In this example, we have constructor with int parameter, So compiler won't generate default constructor for this
   class. We can instruct compiler to generate default construct for this cas by "S() = default;"
   Delete keyword is used in simller way but for other purpose. We can prevent creation of making constructor deleted.
   OR we can prevent creation of object in particular way by makeing particular constructor deleted.
*/
using namespace std;
#include <iostream>
class S {
  int x;
public:
  S(int x): x(x) {}
  S(int x, int y) = delete; // prevent object creation using two input parameter.
  S() = default; // Create default constructor.
  virtual ~S() = default; // Create default destructor
};

int main() {
  S a();
  S b(1);
  // S c(1,2); //  restricted/disabled.
  cout << "Hello world!";
}
