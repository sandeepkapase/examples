// [[file:~/github/prep/ds_algorithm/sorting/Questions.org::c++ insertion_sort_example1 example.][c++ insertion_sort_example1 example.]]
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

void Data::sort(sortorder sort) { // Actual insertion sort algorithm
  for (auto itr=v.begin()+1; itr != v.end(); itr++) {
    auto jitr=v.begin();

    // Identify location where current *itr can be inserted.
    // jitr will be the location where current *itr can be inserted.
    if (sort == ASCENDING) while (jitr != itr && *itr > *jitr) {jitr++;}
    else while (jitr != itr && *itr < *jitr) {jitr++;}

    auto val = *itr; // sort value as it's going to be overwritten while moving array from jitr to itr by one position.
    auto tmpitr = itr;
    while (tmpitr != jitr) { *tmpitr= *(tmpitr-1);tmpitr--;} // move array from jitr to itr by one position
    *jitr= val; // After moving array now we can insert elemnt to jitr.
  }
  sorted = sort; // helper
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
// c++ insertion_sort_example1 example. ends here
