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
      vector<int> v;
      sortorder sorted;
      void MergeSort(vector<int> arr, int start, int end);
      void Merge(vector<int> arr, int start, int mid, int end);
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

    void Data::sort(sortorder sort) { // Merge sort wrapper
      MergeSort(v, 0, v.size());
      sorted = sort;
    }
    void Data::MergeSort(vector<int> arr, int start, int end) {
      if (start < end) {
        cout << "\nstart : " << start << " end: " << end;
        auto mid = (start+end)/2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        Merge(arr, start, mid, end);
        sleep(1);
      }
    }
void Data::Merge(vector<int> arr, int start, int mid, int end) {
    cout << "\nInside merge\n";
  int n1 = mid-start+1;
  int n2 = end-mid;
  int M[n1], N[n2];
  int i=0, j=0, k=start;
  while(i++<n1) M[i]=arr[start+i];
  while(j++<n2) M[j]=arr[mid+j+1];
  i=j=0;
  while (i<n1 && j<n2) {
    if (M[i] < N[j]) {
      arr[k] = M[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while(i<n1) { arr[k] = M[i]; i++; }
  while(j<n2) { arr[k] = M[j]; j++; }
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
