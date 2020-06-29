// [[file:~/github/prep/ds_algorithm/sorting/Questions.org::c++ bubble_sort_example1 example.][c++ bubble_sort_example1 example.]]
#include <map>
#include <list>
#include <deque>
#include <thread>
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>
#include <unistd.h>
#include <tuple>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>






using namespace std;
enum sortorder { ASCENDING, DESCENDING, NOSORT };
class Data {
private:
  vector<int> v;
  sortorder sorted;
public:
  explicit Data ();
  void print ();
  void sort(sortorder);
};

Data::Data () { // helper
  srand (time(NULL));
  v.resize(5);
  for( auto &i: v) { i=rand()%99; }
  sorted = NOSORT;
}

void Data::print () { // helper
  switch(sorted) {
  case NOSORT: cout << endl << "Unordered  Data:"; break;
  case ASCENDING: cout << endl << "Sorted (A) Data:"; break;
  case DESCENDING: cout << endl << "Sorted (D) Data:"; break;
  }
  for( auto &i: v)
    cout << " " << i ;
}

void Data::sort(sortorder sort) { // Actual bubble sort algorithm
  for (auto i=0; i < v.size(); i++) {
    for(auto itr=v.begin(); itr != v.end()-i-1; itr++) {
      if (sort == ASCENDING && *itr > *(itr+1)) swap(*itr, *(itr+1));
      else if (sort == DESCENDING && *itr < *(itr+1)) swap(*itr, *(itr+1));
    }
  }
  sorted = sort;
}

int main(int argc, char*argv[]) {
  Data data;
  data.print();
  data.sort(ASCENDING);
  data.print();
  data.sort(DESCENDING);
  data.print();
  return 0;
}
// c++ bubble_sort_example1 example. ends here
