using namespace std;
#include <iostream>
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
