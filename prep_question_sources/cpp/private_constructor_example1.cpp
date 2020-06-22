// [[file:~/github/prep/cpp/Questions.org::private constructor example 1][private constructor example 1]]
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

class base {
private:
  base() {}
};
int main() {
  cout << endl << "Hello world!";
  //base b; // Fails. Can not create object with private constructor.
  base *b; // Possible. Its just pointer.
  //base *b1 = new base; // Fail, constructor can not called.
  delete b ; // Allow. As it don't have access to destructor.
  base *b2 = (base *)malloc(sizeof(base)); // Possible
  free(b2); // free dealocate memory and does not guarantee release of other resource done in destructor.
  return 0;
}
// private constructor example 1 ends here
