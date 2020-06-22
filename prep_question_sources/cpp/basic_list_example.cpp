// [[file:~/github/prep/cpp/Questions.org::c++ list example.][c++ list example.]]
#include <list>
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






//#include <list>
  using namespace std;
  ostream & operator << (ostream &c, const list<int>&l) {for_each(l.begin(), l.end(), [&c](const auto &i) {c << " " << i ;}); return c;}
  int main(int argc, char*argv[]) {
    list<int> l1(5);
    list<int> l2(5);
    iota(l1.begin(), l1.end(),0);
    iota(l2.begin(), l2.end(),5);
    cout << "\nl1: " << l1;
    cout << "\nl2: " << l2;
    // Assign
    l1.assign({2,4,6,8});
    cout << "\nAfter assignment l1: " << l1;
    l1.assign(5,111);
    cout << "\nAfter assignment l1: " << l1;
    l1.assign(l2.begin(), l2.end());
    cout << "\nAfter assignment l1: " << l1;
    l1.push_front(123);
    cout << "\nAfter push front l1: " << l1;
    l1.push_back(321);
    cout << "\nAfter push back l1: " << l1;
    l1.erase(l1.begin());
    cout << "\nErased element from front: " << l1;
    l1.erase(--l1.end());
    cout << "\nErased element from end: " << l1;
    l1.splice(l1.end(), {1,2,3});
    // splice ==> transfer elements
    cout << "\nSplice : " << l1;
    l1.splice(l1.end(), l2);
    cout << "\nSplice : " << l1;
    l2 = {2,6,8,4};
    l1.splice(l1.end(), l2);
    cout << "\nSplice : " << l1;
    l1.sort();
    cout << "\nSort Splice : " << l1;
    l1.unique();
    cout << "\nUnique Splice : " << l1;
    l1.reverse();
    cout << "\nReverse Splice : " << l1;

    l2 = {35,36,37};
    l1.merge(l2);
    cout << "\nMerge Splice : " << l1;
    return 0;
  }
// c++ list example. ends here
