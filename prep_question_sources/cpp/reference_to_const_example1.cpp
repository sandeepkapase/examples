#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
int main(int argc, char*argv[]) {
    int x = 99;
    // const int & const y = x; // Error here
    const int & y = x; // FIX
    // int & const z = x; // Error here
    int & z = x; // FIX
    cout << "Hello world!";
    return 0;
}
