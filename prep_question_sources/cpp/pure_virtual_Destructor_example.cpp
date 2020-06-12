using namespace std;
#include <iostream>
class shape {
public:
  virtual float area() = 0;
//~shape();
  virtual ~shape() = 0;
};
shape::~shape() {
  cout << endl << "Pure virtual desctructor getting called";
}

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
  //shape x; // Error here. Class is abstract
  cout << "Square area: " << s.area();
  return 0;
}
