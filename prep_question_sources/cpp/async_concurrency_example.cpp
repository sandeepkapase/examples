#include <iostream>
#include <unistd.h>






  #include <iostream>
  #include <future>
  #include <unistd.h>
  int asyncfunc(int i) {
    //std::cout << "\nfunction id: " << i;
    return i*i;
  }
  int threadfunc(int i) {
    std::cout << "\nfunction id: " << i;
    return i*i;
  }

  int main() {
    std::future<int> resultasync[10];
    for (int i=0; i<10; i++) {
      resultasync[i] = std::async(asyncfunc, i);
    }
    for (int i=0; i<10; i++) {
      std::cout << "\nResult: " << resultasync[i].get();
    }

    std::thread wthread[10];
    for (int i=0; i<10; i++) {
      wthread[i] = std::thread(threadfunc, i);
}
    for (int i=0; i<10; i++) {
      wthread[i].join();
}

    return 0;
  }
