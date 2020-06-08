#include <iostream>
// pass by address
void testfun(int *p) {
  *p+=1;
  std::cout << std::endl << "pointer:" << *p;
}

// pass by reference
void testfun(int &p) {
  p+=1;
  std::cout << std::endl << "reference:" << p;
}

// pass by value
void testfun(int p) {
  p+=1;
  std::cout << std::endl << "value:" << p;
}


int main() {
  int p = 0;
  int &pref = p; // reference
  int *pptr = &p; // pointer

  //testfun(p) // get compiler error "call of overloaded ‘testfun(int&)’ is ambiguous"
               // typecast call to invoker right function

  // static_cast ==> pointer to function returning void and accepting reference
  static_cast<void(*)(int&)>(testfun)(p);
  // static_cast ==> pointer to function returning void and accepting integer
  static_cast<void(*)(int)>(testfun)(p);
  // static_cast ==> pointer to function returning void and accepting pointer to integer
  static_cast<void(*)(int *)>(testfun)(&p); // pointer testfun call
  
  return EXIT_SUCCESS;
}
