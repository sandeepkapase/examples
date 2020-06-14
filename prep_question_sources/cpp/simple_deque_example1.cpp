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
#include <deque>







using namespace std;

template <typename T>
ostream & operator << (ostream &c, T &t) {for( auto &i: t)  { printf("%3d", i); } ; return c;}
int main(int argc, char*argv[]) {
  deque <int> dq1(7);
  deque <int> dq2(7);
  iota(dq1.begin(), dq1.end(), 0);
  iota(dq2.begin(), dq2.end(), 5);
  cout << string("dq1: ") << dq1;
  cout << string("\ndq2: ") << dq2;
  cout << string("\nSWAP:"); dq1.swap(dq2);
  cout << string("\ndq1: ") << dq1;
  cout << string("\ndq2: ") << dq2;
  dq1.push_front(17);
  cout << string("\npush_front dq1:") << dq1;
  dq1.push_back(18);
  cout << string("\npush_front dq1:") << dq1;
  dq1.pop_front();
  cout << string("\npop_front dq1:") << dq1;
  dq1.pop_back();
  cout << string("\npop_back dq1:") << dq1;
  cout << string("\nfront element dq1:") << dq1.front();
  cout << string("\nback element dq1:") << dq1.back();
  cout << string("\ndq1 size:") << dq1.back();
  cout << string("\nmax size dq1:") << dq1.max_size();
  return 0;
}
