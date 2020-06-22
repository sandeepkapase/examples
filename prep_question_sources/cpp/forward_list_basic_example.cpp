// [[file:~/github/prep/cpp/Questions.org::c++ forward_list basic example.][c++ forward_list basic example.]]
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






using namespace std;
int main(int argc, char*argv[]) {
  forward_list<int> fl1(10);
  forward_list<int> fl2(5);
  iota(begin(fl1), end(fl1), 0); //0 is the starting number
  iota(begin(fl2), end(fl2), 10); //0 is the starting number
  cout << "\nflist l1: " ;
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});
  cout << "\nflist l2: " ;
  for_each(fl2.begin(), fl2.end(), [](int &i){ cout << " " << i ;});

  cout << "\nSwap list";
  fl1.swap(fl2); // This will swap/exchange undelying linked list.
  cout << "\nflist l1: " ;
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});
  cout << "\nflist l2: " ;
  for_each(fl2.begin(), fl2.end(), [](int &i){ cout << " " << i ;});
  cout << "\npoping front element fl1: " << fl1.front() ; fl1.pop_front(); // return none
  cout << "\nfl1 after pop: ";
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});

  cout << "\nemplace_front first element fl1: " << fl1.front(); fl1.emplace_front(999) ;
  cout << "\nfl1 after operation: ";
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});

  auto itr = fl1.begin(); itr++; itr++;
  cout << "\nemplace_after element fl1: " << *itr; fl1.emplace_after(itr,888) ;
  cout << "\nfl1 after operation: ";
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});
  cout << "\ninsert_after element fl1: " << *itr; fl1.insert_after(itr,887) ;
  cout << "\nfl1 after operation: ";
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});
  cout << "\nerase_after element fl1: " << *itr; fl1.erase_after(itr) ;
  cout << "\nfl1 after operation: ";
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});


  // insert another list after iterator. << *itr; fl1.splice_after(itr,{45,67}) ;
  cout << "\nsplice_beforeelement fl1: " << fl1.front(); fl1.splice_after(fl1.before_begin(), fl2);
  cout << "\nfl1 after operation: ";
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});

  forward_list<int> tmpf = {33,22,11};
  //  insert 22,11 at begining of fl1
  cout << "\nsplice_beforeelement fl1: " << fl1.front(); fl1.splice_after(fl1.before_begin(), tmpf, tmpf.begin(), tmpf.end());
  cout << "\nfl1 after operation: ";
  for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});

  // RESIZE forward_list
  cout << "\nBefore resize: " ; for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});
  fl1.resize(5);
  cout << "\nAfter resize: " ; for_each(fl1.begin(), fl1.end(), [](int &i){ cout << " " << i ;});
  cout << "\nis empty fl1: " << fl1.empty();

  return 0;
}
// c++ forward_list basic example. ends here
