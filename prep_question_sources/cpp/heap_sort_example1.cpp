// [[file:~/github/prep/ds_algorithm/sorting/Questions.org::c++ heap_sort_example1 example.][c++ heap_sort_example1 example.]]
#include <climits>
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
    void MinHeapify(int i, int n); // Heapify on index.
    void MaxHeapify(int i, int n); // Heapify on index.
  public:
    explicit Data ();
    void print ();
    void sort(sortorder sort);
  };

  void Data::MinHeapify(int i, int n) {
    //cout << "\nIndex: " << i;
    int l = (i*2)+1;
    int r = (i*2)+2;
    int smallest = i;
    if (Arr[l] < Arr[smallest] && l < n) smallest = l;
    if (Arr[r] < Arr[smallest] && r < n) smallest = r;
    if (smallest != i) {
      swap(Arr[smallest], Arr[i]);
      MinHeapify(smallest, n);
    }
  }

  void Data::MaxHeapify(int i, int n) {
    //cout << "\nIndex: " << i;
    int l = (i*2)+1;
    int r = (i*2)+2;
    int smallest = i;
    if (Arr[l] > Arr[smallest] && l < n) smallest = l;
    if (Arr[r] > Arr[smallest] && r < n) smallest = r;
    if (smallest != i) {
      swap(Arr[smallest], Arr[i]);
      MaxHeapify(smallest, n);
    }
  }

  void Data::sort(sortorder sorder) {
    sorted = sorder;
    // Build heap: This loop ensure that we have min element at beginning
    for (int i = Arr.size()/2; i >= 0; i--)
      if (sorted==ASCENDING) MaxHeapify(i, Arr.size());
      else MinHeapify(i, Arr.size());

    for (int i = Arr.size()-1; i > 0; i--) {
      swap(Arr[0], Arr[i]); // put min element at the end of array.
      if (sorted == ASCENDING) MaxHeapify(0,i); // place min element at beginning from array  0..i ==> i=n-1....1
      else MinHeapify(0,i); // place max element at beginning from array  0..i ==> i=n-1....1
    }
}

  Data::Data () { // helper
    srand (time(NULL));
    Arr.resize(10);
    for( auto &i: Arr) { i=rand()%99; }
  }

  void Data::print () { // helper
    cout << endl << "Data:";
    for(auto &i: Arr) cout << " " << i ;
  }

  int main(int argc, char*argv[]) {
    Data data;
    data.print();
    //data.sort(ASCENDING);
    data.sort(DESCENDING);
    data.print();
    //data.sort(ASCENDING);
    //data.print();
    return 0;
  }
// c++ heap_sort_example1 example. ends here
