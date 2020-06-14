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







using namespace std;

ostream & operator << (ostream &c, priority_queue<int> &q) {priority_queue <int>tmp = q; while(!q.empty()) {cout << " " << q.top(); q.pop();} q=tmp; return c;}

int main(int argc, char*argv[]) {
  priority_queue <int> pq1;
  for (auto i=7; i<14; i++) pq1.push(i);
  cout << "\npqueue: " << pq1 ;
  cout << "\npqueue: " << pq1 ;
  pq1.push(9);
  cout << "\npqueue: " << pq1 ;
  cout << "\npqueue size: " << pq1.size() ;
  return 0;
}
