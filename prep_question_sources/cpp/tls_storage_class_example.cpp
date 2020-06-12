#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <future>
#include <unistd.h>
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
