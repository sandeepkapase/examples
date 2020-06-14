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
#include <set>
#include <map>
#include <iterator>







using namespace std;
ostream & operator << (ostream &c, multimap<int,string> &mp) {
  cout << "\nmmap:{ ";
  for(auto &i: mp) { cout << " (" << i.first << "," << i.second << ")"; }
  cout << " }";
  return c;
}


ostream & operator << (ostream &c, map<int,string> &mp) {
  cout << "\nmap:{ ";
  for(auto &i: mp) { cout << " (" << i.first << "," << i.second << ")"; }
  cout << " }";
  return c;
}

int main(int argc, char*argv[]) {
  //map<int, int> map1 = {pi{1,2}};
  map<int, string> map1 = map<int,string>{{1,"one"}, {2,"two"}, {3, "three"}, {4, "four"}, {5, "five"}};
  cout << map1;

  map1.insert({6, "six"});
  map1.insert({7, "seven"});
  cout << "\nAfter 6,7 insert map:" << map1;
  map1.erase(2);
  cout << "\nAfter key '2' insert map:" << map1;
  map1.erase(map1.find(4), ++map1.find(5));
  cout << "\nAfter range delete from 4 to 5 map:" << map1;
  auto itr = map1.lower_bound(2); // first element greater than key
  cout << "\nlower bount: " << itr->first << " " <<  itr->second;
  itr = map1.upper_bound(2); // first element not less than key
  cout << "\nupper bount: " << itr->first << " " <<  itr->second;
  cout << "\nsize of map: " << map1.size();
  cout << "\nAfter map clear.";
  map1.clear();
  cout << map1;
  cout << "\nAdded element with subscription";
  map1[1] = "100";
  cout << map1;
  cout << "\nCount: " << map1.count(1);
  cout << "\nMultMap :";
  multimap<int,string>mmap1 = multimap<int,string>{{1,"one"}, {1,"two"}, {3, "three"}, {4, "four"}, {5, "five"}};
  cout << mmap1;


  return 0;
}
