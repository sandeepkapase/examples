#include <iostream>
// warning : use of ‘auto’ in parameter declaration only available with ‘-fconcepts’
// g++ -fconcepts file.cpp

auto somefunction(auto x, auto y) {
  return x*y;
}

int main() {
  std::cout << std::endl << somefunction(1,4);
  std::cout << std::endl << somefunction(1.1,4);
  std::cout << std::endl << somefunction(1.1,0.3);
  std::cout << std::endl << somefunction(9,0.3);
  float x = somefunction(1.1,4.4); // return assumed float
  std::cout << std::endl << x;
  int y = somefunction(1.1,4.4); // return assumed int
  std::cout << std::endl << y;
}
