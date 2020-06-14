#include <iostream>
#include <unistd.h>
#include <algorithm>






 using namespace std;
 #include <iostream>
 #include <vector>

 auto printVector = [] (const int &i) {std::cout << i << " ";};
 ostream & operator << (ostream &cout, vector<int> &v) {
   for( const auto &i: v) cout << " " << i ;
   return cout;
 }

 int main(int argc, char*argv[]) {
   vector<int> v;
   vector<int>::iterator  vtr = v.begin();
   auto itr = v.begin();
   for (auto i = 1 ; i < 20; i++) {
     v.push_back(i);
     //v.pop_back(); // remove element from end
     itr = v.begin();
     // observe address of first element to see element are moved to memory location.
     //printf("\nelemenet : %2d size: %2d capacity: %2d Address:%p", *itr, v.size(), v.capacity(), itr);
   }
   // note that resize does not immediately reduce capacity.
   // Also, iterator will have only one element to iterate now.
   v.resize(1);  // note that resize does not immediately reduce capacity.yyp
   printf("\nelemenet : %2d size: %2d capacity: %2d Address:%p", *itr, v.size(), v.capacity(), itr);

   // This is max size for vector i.e. we won't be able to grow beyong it.
   cout << "\nMax size: " << v.max_size();

   // insert element at begining
   v.insert(v.begin(), 123);
   // emplace is similar to insert but it make use of move constructor avoid copy objects
   // This is useful when size of object is bigger.
   // v.emplace(v.begin(), 123);
   cout << "\nAfter insert at beginning:" << v;
   //for_each(v.begin(), v.end(), printVector);

   // insert element at after first element
   v.insert(v.begin()+1, 124);
   cout << "\nAfter insert at after first element:" << v;

   // insert element at end
   v.insert(v.end(), 126);
   cout << "\nAfter insert at end:" << v;

   // insert element before end
   v.insert(v.end()-1, 125);
   cout << "\nAfter insert at end:" << v;

   // insert first two element to the end
   v.insert(v.end(), v.begin(), v.begin()+2);
   cout << "\nFirst two at end:" << v;

   // insert first two element from array to vector.
   int intarr[] = {1,2,4};
   v.insert(v.end(), intarr, intarr+2);
   cout << "\nFirst two at end from array:" << v;

   // insert 300 at the end for 4 times
   v.insert(v.end(), 4, 300);
   cout << "\nFirst two at end from array:" << v;

   cout << "\nBefor Shrink Capacity";
   printf("\nsize: %2d capacity: %2d", v.size(), v.capacity());
   // Notice change in capacity
   v.shrink_to_fit();
   cout << "\nAfter Shrink Capacity";
   printf("\nsize: %2d capacity: %2d", v.size(), v.capacity());
   v.erase(v.begin());
   cout << "\nErased element from beginnig:" << v;
   v.erase(v.begin()+5);
   cout << "\nErased 5th element from beginnig:" << v;

   vector<int> w = {7,6,4};
   printf("\nBefore swap address v:%p w:%p", v.begin(), w.begin());
   // After this you can see than only underlying allocated buffer
   // will only be exchanged and not actual swapping of elements or new allocation/deallocations.
   v.swap(w);
   cout << "\nAfter swap v:" << v;
   cout << "\nAfter swap w:" << w;
   printf("\nBefore swap address v:%p w:%p", v.begin(), w.begin());

   cout << "\nBefore clearing w: size:" << w.size() << " capacity:" << w.capacity();
// Note that only size will be reduced and not capacity
   w.clear();
   cout << "\nAfter clearing w: size:" << w.size() << " capacity:" << w.capacity();
   w.assign(7,300);
   cout << "\n300 assignment :" << w;
   w.assign(intarr, intarr+3);
   cout << "\nThree elements from int arr" << w;
   w.assign(v.begin(), v.end()-1);
   cout << "\nCopy from other vector: " << w;
   cout << "\nElement at 0: " << w.at(0);
   return 0;

 }
