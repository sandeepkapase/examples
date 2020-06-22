// [[file:~/github/prep/cpp/Questions.org::c++ stl stack example.][c++ stl stack example.]]
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>
#include <list>
#include <tuple>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>






using namespace std;
template<typename T>
ostream & operator << (ostream &c, T &q) { c << string("\nSet:"); for_each(q.begin(), q.end(), [&](auto &i) { cout << string(" " )<< i ; }); return c;}

int main(int argc, char*argv[]) {
  set<int> set1 = {1,2,3,4};
  cout << set1;
  set1.insert(11);
  cout << string("\nAfter Insert 11:") << set1;
  set1.insert(11);
  cout << string("\nAfter Again Insert 11:") << set1;
  auto set2 = set1;
  cout << string("\nNew assigned set2:") << set2;
  // exclude first and last element.
  set<int> set3(++set1.begin(), ++set1.end());
  cout << string("\nNew partial assigned set3:") << set3;

  set1.erase(11);
  cout << string("\nerased 11 from set1:") << set1;
  auto itr = set1.find(11);
  if (itr == set1.end()) cout << string("\n11 not found in set1"); else cout << string("\n11 found in set1");
  itr = set1.find(4);
  if (itr == set1.end()) cout << string("\n4 not found in set1"); else cout << string("\n4 found in set1");
  if (!set1.count(11)) cout << string("\n11 not found in set1"); else cout << string("\n11 found in set1");
  if (!set1.count(11)) cout << string("\n4 not found in set1"); else cout << string("\n4 found in set1");
  vector <int>v(10);
  auto itrs= set_union(set1.begin(), set1.end(), set3.begin(), set3.end(), v.begin());
  v.resize(itrs - v.begin());
  cout << v;

  return 0;
}
// c++ stl stack example. ends here
