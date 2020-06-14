#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <list>
#include <tuple>
#include <array>






using namespace std;

template <typename T>
ostream & operator << (ostream &c, T &t) {for( auto &i: t)  { printf("%2d", i); } ; return c;}

int main(int argc, char*argv[]) {
  array<int, 5> iarr1;
  array<int, 5> iarr2;
  iota(iarr1.begin(), iarr1.end(), 0);
  iota(iarr2.begin(), iarr2.end(), 5);
  cout << string("arr1: ") << iarr1 << endl;
  cout << string("arr2: ") << iarr2 << endl;
  cout << string("\nSWAP") << endl; iarr1.swap(iarr2);
  cout << string("arr1: ") << iarr1 << endl;
  cout << string("arr2: ") << iarr2 << endl;
  cout << string("\nFILL") << endl; iarr1.fill(1); iarr2.fill(2);
  cout << string("arr1: ") << iarr1 << endl;
  cout << string("arr2: ") << iarr2 << endl;
  cout << string("\nSIZE") << endl; iarr1.fill(1); iarr2.fill(2);
  cout << string("arr1: ") << iarr1.size() << endl;
  cout << string("arr2: ") << iarr2.size() << endl;
  iota(iarr1.begin(), iarr1.end(), 0);
  iota(iarr2.begin(), iarr2.end(), 5);
  cout << string("arr1: ") << iarr1 << endl;
  cout << string("arr1 front : ") << iarr1.front() << endl;
  cout << string("arr1 back: ") << iarr1.back() << endl;
  cout << string("arr1 at 3: ") << iarr1.at(3) << endl;
  cout << string("arr1 data: ") << *(iarr1.data()+4) << endl;
  return 0;
}
