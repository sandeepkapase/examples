using namespace std;
#include <iostream>
class shape {
public:
  virtual float area() = 0;
};

class square: public shape {
private:
  float side;
public:
  square(float s): side(s) {}
  float area() {
    return side*side;
  }
};
int main() {
  square s(3);
  cout << "Square area: " << s.area();
  return 0;
}
