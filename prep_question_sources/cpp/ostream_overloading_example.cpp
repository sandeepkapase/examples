#include <iostream>
#include <unistd.h>






  using namespace std;
  #include <iostream>
  class point {
  private:
    int x,y;
  public:
    point (int x, int y): x(x), y(y) {}
    friend ostream & operator << (ostream &s, point &p);
  };

  ostream & operator << (ostream &s, point &p) {
    s << "Value of x: " << p.x << " Value of y: " << p.y ;
    return s;
  }
  int main() {
point p(11,12);
    cout << p;
    return 0;
  }
