#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
#include <memory>
class Node {
public:
  Node() { cout << "\nConstructor called";}
  ~Node() { cout << "\nDestructor called";}
  //std::shared_ptr<Node> parent;
  std::weak_ptr<Node> parent;
};
int main() {
  std::shared_ptr<Node>child(new Node);
  // Due to below reference object destructor will not gets called, not destroyed.
  // To fix this we can replace shared_ptr in class with weak_ptr.
  child->parent = child; // only element in list, self referencing.
  cout << "\nUse count :" << child.use_count();
  cout << "\nUse count :" << child->parent.use_count();
  return 0;
}
