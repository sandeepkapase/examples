using namespace std;
struct Base {
  virtual Base * copy_clone() const { cout << "\nBase clone/copy call"; return new Base(*this);}
  void whoAmI() {cout << "\nThis is base class";}
};
struct Derived : public Base {
  virtual Derived * copy_clone() const override {cout << "\nDerived clone/copy call"; return new Derived(*this);}
  void whoAmI() {cout << "\nThis is derived class";}
};

int main(int argc, char*argv[]) {
  Derived *d; Base *b;
  b = d = new Derived;
  auto x = d->copy_clone();
  auto y = b->copy_clone();
  x->whoAmI();
  y->whoAmI();
  return 0;
}
