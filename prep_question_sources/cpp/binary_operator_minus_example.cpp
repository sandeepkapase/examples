#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class point {
private:
  int x,y;
public:
  point(int x=1, int y=1): x(x), y(y) {}
  void printpoint(){ cout<< "\nX: " << x << " Y: " << y;}
  point operator +(const point &p) { cout << "\nplus Bin operator call";  point s(x+p.x, y+p.y); return s;}
  point operator -(const point &p) { cout << "\nminus Bin operator call";  point s(x-p.x, y-p.y); return s;}
  point operator *(const point &p) { cout << "\nmultiplication Bin operator call";  point s(x*p.x, y*p.y); return s;}
  point operator /(const point &p) { cout << "\ndivision Bin operator call";  point s(x/p.x, y/p.y); return s;}
  point operator %(const point &p) { cout << "\nmodulus Bin operator call";  point s(x%p.x, y%p.y); return s;}
  // This can be done with fried function as well.
  //friend point operator %(const point &p, const point &q);
};
  //point operator %(const point &p, const point &q) { cout << "\nF Modulus Bin operator call";  point s(p.x%q.x, p.y%q.y); return s;}
int main() {
  point p,q,r;
  r = p+q;
  r.printpoint();
  r = p-q;
  r.printpoint();
  r = p*q;
  r.printpoint();
  r = p/q;
  r.printpoint();
  r = p%q;
  r.printpoint();

  return 0;
}
