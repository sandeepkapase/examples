#include <iostream>

using namespace std;

int main()
{
  // Shortest form
  []{}(); // does nothing. its like void fun(void) {}}

  // simple lambda that print hello world.
  auto helloWorld= []{ cout << endl << "Hello world"; };
  helloWorld(); // now call the function

  // Lambda that accept parameters
  auto sum = [] (int i, int j) { return i+j; };
  cout << endl << sum(1,2); // now call the function

  // Lambda that accept parameters and explicitely specify return type.
  // In example below, we are specifying float as return type.
  auto div = [] (int i, int j) -> float { return i/j; };
  printf("\n%.2f", div(5,2)); // now call the function

  string name = "sandeep";
  auto printstring = [&] (const string &str) { cout << endl << "External string: " << name ; } ;
  [&] (const string &str) { cout << endl << "External string: " << name ; }(name);
  //printstring(name);
}
