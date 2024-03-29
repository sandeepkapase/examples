// [[file:~/github/prep/ds_algorithm/sorting/Questions.org::c++ merge_sort_example1 example.][c++ merge_sort_example1 example.]]
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
  void mergeSort(int start, int end); // Actual merge sort function.
  void merge(int start, int mid, int end); // Acutal merge sort function.
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
  mergeSort(0, Arr.size()-1);
  sorted = sort;
}

void Data::merge(int start,int mid, int end)
{
  int n1 = mid - start + 1, L[n1];
  int n2 = end - mid, R[n2];
  int i=0, j=0, k=start;

  /* Copy data to auxiliary arrays */
  while (i < n1) L[i++] = Arr[start + i];
  while (j < n2) R[j++] = Arr[mid + 1 + j];

  /* copy data in sorted order from auxiliary array */
  for (i = 0, j = 0; i < n1 && j < n2; k++)
    if (sorted == ASCENDING)
      Arr[k] = L[i] <= R[j] ?  L[i++] : R[j++] ;
    else
      Arr[k] = L[i] >= R[j] ?  L[i++] : R[j++] ;

  while (i < n1) Arr[k++] = L[i++]; // copy remaining data if any
  while (j < n2) Arr[k++] = R[j++]; // copy remaining data if any
}

void Data::mergeSort(int start, int end) {
  if(start < end) {
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid+1, end);
    merge(start, mid, end);
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
// c++ merge_sort_example1 example. ends here
