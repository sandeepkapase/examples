// [[file:~/github/prep/ds_algorithm/sorting/Questions.org::c++ quick_sort_example1 example.][c++ quick_sort_example1 example.]]
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
  vector<int> Arr;
  sortorder sorted;
  void quickSort(int start, int end); // Actual merge sort function.
  int partition(int start, int end); // Acutal merge sort function.
public:
  explicit Data ();
  void print ();
  void sort(sortorder); // Merge sort wrapper.
};

Data::Data () { // helper
  srand (time(NULL));
  Arr.resize(10);
  for( auto &i: Arr) { i=rand()%99; }
  sorted = NOSORT;
}

void Data::print () { // helper
  switch(sorted) {
  case NOSORT: cout << endl << "Unordered  Data:"; break;
  case ASCENDING: cout << endl << "Sorted (A) Data:"; break;
  case DESCENDING: cout << endl << "Sorted (D) Data:"; break;
  }
  for( auto &i: Arr)
    cout << " " << i ;
}

void Data::sort(sortorder sort) { // Merge sort wrapper
  sorted = sort;
  quickSort(0, Arr.size()-1);
}

int Data::partition(int start, int end)
{
  auto pivot = Arr[end];
  auto nextPivot = start-1;
  for (auto i=start; i<=end-1 ; i++) {
    if (Arr[i] < pivot && sorted == ASCENDING) {
      nextPivot++;
      swap(Arr[nextPivot], Arr[i]);
    } else if (Arr[i] > pivot && sorted == DESCENDING) {
      nextPivot++;
      swap(Arr[nextPivot], Arr[i]);
    }
  }
  nextPivot++;
  swap(Arr[nextPivot], Arr[end]);
  return nextPivot;
  return 0;
}

void Data::quickSort(int start, int end) {
  if(start < end) {
    int pivot = partition(start, end);
    quickSort(start, pivot-1);
    quickSort(pivot+1, end);
  }
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
// c++ quick_sort_example1 example. ends here
