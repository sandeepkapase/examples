#include <iostream>
#include <unistd.h>






  using namespace std;
  #include <iostream>
  class point {
  private:
    int x,y;
  public:
    point(int x=1, int y=1): x(x), y(y) {}
    void printpoint() { cout<< "\nX: " << x << " Y: " << y;}
    point operator --() { --x; --y; return *this;}
    point operator ++() { ++x; ++y; return *this;}
    point operator --(int) { point p(x,y); x++; y++; return p;} // post
    point operator ++(int) { point p(x,y); x--; y--; return p;} // post
};
  int main() {
    point p;
    p.printpoint();
    --p;
    p.printpoint();
    ++p;
    p.printpoint();
    point q = p++;
    p.printpoint();
    q.printpoint();
    q = p--;
    p.printpoint();
    q.printpoint();
    return 0;
  }
