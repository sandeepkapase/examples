// [[file:~/github/prep/cpp/Questions.org::fix for enum using enum class][fix for enum using enum class]]
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






using namespace std;
enum class CarColor {Black, Blue, Red};
enum class BikeColor {Black, Blue, Red};
int main() {
  CarColor c = CarColor::Blue;
  BikeColor d = BikeColor::Blue;
  cout << "\nColor: " << static_cast<std::underlying_type<CarColor>::type>(c);
  cout << "\nColor: " << static_cast<std::underlying_type<BikeColor>::type>(d);
  return 0;
}
// fix for enum using enum class ends here
