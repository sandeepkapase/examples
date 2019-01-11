#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
#include <queue>
#include <iostream>

using namespace std;

class base {
public:
  virtual void DoIt(void) {
    cout << endl << "This is common" << endl;
  }
};

class derivedA:public base {
public:
  void DoIt(void) {
    cout << endl << "This is commonA" << endl;
  }

  void Afun(void) {
    cout << endl << "I am Afun" << endl;
  }
};


class derivedB:public base {
public:
  void DoIt(void) {
    cout << endl << "This is commonB" << endl;
  }

  void Afun(void) {
    cout << endl << "I am BFun" << endl;
  }
};

int main (void) {
  base *ptr;
  derivedA *aptr;
  derivedB *bptr;

  derivedA da;
  derivedB db;

  //ptr = &da;
  ptr = &db;
  ptr->DoIt();

  aptr = dynamic_cast<derivedA *>(ptr);
  if (aptr != NULL)
    aptr->DoIt();

  bptr = dynamic_cast<derivedB *>(ptr);
  if (bptr != NULL)
    bptr->DoIt();
  return 0;

}
