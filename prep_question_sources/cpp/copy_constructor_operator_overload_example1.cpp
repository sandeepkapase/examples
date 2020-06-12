using namespace std;
#include <iostream>
class S {
private:
  int x,y;
  S(S &ref) { cout << endl << "copy constructor called"; this->x = ref.x; this->y = ref.y ; }
  void operator = (S &ref) { cout << endl << "= overload called"; this->x = ref.x; this->y = ref.y ; }
public:
  S(int x, int y): x(x), y(y) {}
};
int main() {
  S s(1,2);
  S t = s; // copy constructor call.
  t = s; // = to overload operator
  return 0;
}
