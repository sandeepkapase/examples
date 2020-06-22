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

// class Base final { // FIX: prevent inheritabce of this class
 class Base { // append "final" to class name
 };
 class Derived : public Base {};

 int main()
 {
   Derived d;
   Base &b = d;
   return 0;
 }
