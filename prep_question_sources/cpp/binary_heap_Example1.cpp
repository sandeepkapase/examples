// [[file:~/github/prep/ds_algorithm/Questions.org::c++ Binary_heap_operations_example1 example.][c++ Binary_heap_operations_example1 example.]]
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
  int currentSize;
public:
  explicit Data ();
  void MinHeapify(int i); // Heapify on index.
  void Insert(int val);
  int ExtractMin();
  void DeleteKey(int i);
  void print ();
  void RandomFill();
  void FillData();
};

void Data::MinHeapify(int i) {
  //cout << "\nIndex: " << i;
  int l = (i*2)+1;
  int r = (i*2)+2;
  int smallest = i;
  if (Arr[l] < Arr[smallest] && l < currentSize) smallest = l;
  if (Arr[r] < Arr[smallest] && r < currentSize) smallest = r;
  if (smallest != i) {
    swap(Arr[smallest], Arr[i]);
    MinHeapify(smallest);
  }
}
void Data::Insert(int val) {
  if (currentSize == Arr.size()) {
    cout << "\nHeap overflow";
  }
  currentSize++;
  auto i = currentSize-1;
  Arr[i] = val;
  while (i != 0 && Arr[i] < Arr[(i-1)/2]) {
    swap(Arr[i] , Arr[(i-1)/2]);
    i = (i-1)/2; // parent index
  }
}
int Data::ExtractMin() {
  if (currentSize <=0 )
    return INT_MAX;
  if (currentSize == 1 ) {
    currentSize--;
    return Arr[0];
  }
  auto ret = Arr[0];
  Arr[0] = Arr[currentSize-1];
  currentSize--;
  MinHeapify(0);
  return ret;
}

void Data::DeleteKey(int i) {
  if ( i >= currentSize) {
    cout << "\nInvalid delete index: index out of range";
    return ;
  }
  Arr[i] = INT_MIN;
  while(i!=0) {
    swap(Arr[i], Arr[(i-1)/2]);
    i = (i-1)/2;
  }
  ExtractMin();
}



Data::Data () { // helper
  srand (time(NULL));
  Arr.resize(10);
  currentSize = 0;
  //for( auto &i: Arr) { i=rand()%99; }
}
void Data::RandomFill() { // helper
  srand (time(NULL));
  currentSize = 10;
  for( auto &i: Arr) { i=rand()%99; }
}
void Data::FillData() { // helper
  for (int i=0; i<10; i++) {
    auto d = rand()%99;
    Insert(d);
  }
}



void Data::print () { // helper
  cout << endl << "Data:";
  for(auto i=0; i< currentSize; i++)
    cout << " " << Arr[i] ;
}

int main(int argc, char*argv[]) {
  Data data;
  data.FillData();

  data.print();
  data.DeleteKey(3);
  data.print();
  data.DeleteKey(5);
  data.print();

  //for (int i=0; i<10; i++) {
  //data.print();
  //cout << endl << data.ExtractMin();
  /*for (int i=9; i>=0; i--) {
    data.MinHeapify(i);
    }*/
  return 0;
}
// c++ Binary_heap_operations_example1 example. ends here
