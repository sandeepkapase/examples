// [[file:~/github/prep/ds_algorithm/sorting/Questions.org::c++ selection_sort_example1 example.][c++ selection_sort_example1 example.]]
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

void Data::sort(sortorder sort) { // Actual selection sort algorithm
  for (auto itr=v.begin(); itr != v.end(); itr++) { // initially sorted array is of size zero.
    auto min_itr = itr;
    for (auto jitr=itr+1; jitr != v.end(); jitr++) // Find index with min value
      if (sort == ASCENDING && *jitr > *min_itr) min_itr = jitr;
      else if (sort == DESCENDING && *jitr < *min_itr) min_itr = jitr;
    swap(*min_itr, *itr); // put minimum value from unsorted array to end of sorted array.
  }
  sorted = sort; // helper flag
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
// c++ selection_sort_example1 example. ends here
