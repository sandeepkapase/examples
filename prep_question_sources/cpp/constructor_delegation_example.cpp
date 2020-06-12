using namespace std;
# include <iostream>
  class Foo {
  public:
    Foo(char x, int y) {cout << "\nTwo parameter constructor";}
    Foo(int y) : Foo('a', y) { cout << "\nOne param constructor.";} // Foo(int) delegates to Foo(char,int)
  };
  #include <iostream>
  int main() {
    Foo f(1);
    return 0;
  }
