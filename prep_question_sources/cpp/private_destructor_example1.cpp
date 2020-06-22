// [[file:~/github/prep/cpp/Questions.org::private destructor example 1][private destructor example 1]]
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
  ~base() {}
};
int main() {
  //base b; // Fails. Can not create object with private destructor.
  base *b; // Possible. Its just pointer.
  base *b1 = new base; // Possible, we are dynamically allocating memory.
                       // In case of private constructor, it is not possible.
  //delete b1 ; // Fail. As it don't have access to destructor.
  base *b2 = (base *)malloc(sizeof(base)); // Possible
  free(b2); // free dealocate memory and does not guarantee release of other resource done in destructor.
  cout << "Hello world!";
  return 0;
}
// private destructor example 1 ends here
