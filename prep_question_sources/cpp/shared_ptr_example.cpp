#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
#include <memory> // smart pointers.

int main() {
  std::shared_ptr<int> p(new int(11));
  std::shared_ptr<int> q = std::make_shared<int>(22);
  std::cout << "\nValue p: " << *p << std::endl;
  std::cout << "\nValue q: " << *q << std::endl;
  std::cout << "\nReference count p: " << p.use_count() << std::endl;
  std::cout << "\nReference count q: " << q.use_count() << std::endl;
  std::shared_ptr<int> parr[100];
  for (int i = 0 ; i < 100 ; i++) {
    parr[i] = p;
  }
  std::cout << "\nReference count p: " << p.use_count() << std::endl;
  for (int i = 0 ; i < 100 ; i++) {
    parr[i].reset();
  }
  std::cout << "\nReference count p: " << p.use_count() << std::endl;

  return 0;
}
