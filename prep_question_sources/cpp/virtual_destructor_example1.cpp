using namespace std;
#include <iostream>
class base {
private:
  ~base() {}
};
int main() {
  //base b; // Fails. Can not create object with private destructor.
  base *b; // Possible. Its just pointer.
  base *b1 = new base; // Possible, we are dynamically allocating memory.
  //delete b1 ; // Fail. As it don't have access to destructor.
  base *b2 = (base *)malloc(sizeof(base)); // Possible
  free(b2); // free dealocate memory and does not guarantee release of other resource done in destructor.
  cout << "Hello world!";
  return 0;
}
