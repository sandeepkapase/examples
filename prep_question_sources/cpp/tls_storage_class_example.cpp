// [[file:~/github/prep/cpp/Questions.org::TLS storage class][TLS storage class]]
#include <thread>
#include <unistd.h>
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
thread_local int gCount=4;

void threadfunc(void) {
  sleep(rand()%5);
  for (int i=0; i<5; i++) {
    gCount+=rand()%7;
  }
  std::cout << "\nThread Exit data: " << gCount;
}

int main() {
  srand (time(NULL));
  std::thread wthread[10];
  std::cout << "\nBegin data: " << gCount;
  for (int i=0; i<10; i++) {
    wthread[i] = std::thread(threadfunc);
  }
  for (int i=0; i<10; i++) {
    gCount+=rand()%9;
    wthread[i].join();
  }
  std::cout << "\nEnd data: " << gCount;
}
// TLS storage class ends here
