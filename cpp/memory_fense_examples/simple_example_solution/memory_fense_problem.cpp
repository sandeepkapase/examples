/* Example should be compile with  g++ -O3 -pthread <filename>.cpp to
   enable optiomizations */
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

int main(int argc, char** argv)
{
    bool flag = false;

    thread t1([&]() {
        this_thread::sleep_for(100ms);
        cout << "t1 started" << endl;
        flag = true;
        cout << "t1 signals and exits" << endl;
    });

    thread t2([&]() {
        cout << "t2 started" << endl;
        while(flag == false) ;
        cout << "t2 got signaled and exits" << endl;
    });

    t1.join();
    t2.join();

    return 1;
}
