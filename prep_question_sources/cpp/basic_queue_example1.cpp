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
ostream & operator << (ostream &c, queue<int> &q) {queue <int>tmp = q; while(!q.empty()) {cout << " " << q.front(); q.pop();} q=tmp; return c;}

int main(int argc, char*argv[]) {
  queue <int> q1, q2;
  for (auto i=9; i < 17; i++) q1.push(i);
  cout << "\nQueue: " << q1;
  cout << "\nFront element: " << q1.front();
  q1.pop();
  cout << "\nQueue after pop: " << q1;
  q1.push(17);
  cout << "\nQueue after push: " << q1;
  q1.emplace(99);
  cout << "\nQueue after emplace: " << q1;
  q1.swap(q2);
  cout << "\nQueue q1 after swap: " << q1;
  return 0;
}
