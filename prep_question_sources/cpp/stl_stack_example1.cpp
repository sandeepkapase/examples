#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <list>
#include <tuple>
#include <array>
#include <queue>
#include <stack>







using namespace std;

ostream & operator << (ostream &c, stack<int> &q) {stack <int>tmp = q; while(!q.empty()) {cout << " " << q.top(); q.pop();} q=tmp; return c;}

int main(int argc, char*argv[]) {
  stack <int> stk1,stk2;
  for (auto i=7; i<14; i++) { stk1.push(i); stk2.push(7+i); }
  cout << "\nstack1: " << stk1 ;
  cout << "\nstack2: " << stk2 ;
  stk1.push(9);
  cout << "\nstk1 after push 9: " << stk1 ;
  cout << "\nstk1 top: " << stk1.top() ;
  stk1.pop() ;
  cout << "\nstk1 after pop: " << stk1 ;
  cout << "\npqueue size: " << stk1.size() ;
  stk1.swap(stk2) ;
  cout << "\nafter swap stk1: " << stk1;
  return 0;
}
