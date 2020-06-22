// [[file:~/github/prep/cpp/Questions.org::friend class example][friend class example]]
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

class LinkedList{
public:
  int search() {
  }

};
class Node {
private:
  int key;
  Node* next;
  /* Other members of Node Class */

  // Declaration that LinkedList is friend class it should be allowed to access private memeber of Node class
  friend class LinkedList;
  // We can also make particular method of class as friend instead of complete class
  friend int LinkedList::search();
};
int main() {
  return 0;
}
// friend class example ends here
