using namespace std;
#include<iostream>
#include <future>
#include<unistd.h>
#define MAX_THREAD 10

void worker(void) {
    cout << endl << "started worker";
    for (int i=0 ; i < 1000000000; i++);
    cout << endl << "finishing worker";
}

int main() {
    std::future<void> t[MAX_THREAD];
    cout << endl << "Started main";
    for (int i=0; i<MAX_THREAD;i++) t[i] = async(worker);
    for (int i=0; i<MAX_THREAD;i++) t[i].wait();
}
