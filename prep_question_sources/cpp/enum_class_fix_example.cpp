#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
enum class CarColor {Black, Blue, Red};
enum class BikeColor {Black, Blue, Red};
int main() {
  CarColor c = CarColor::Blue;
  BikeColor d = BikeColor::Blue;
  cout << "\nColor: " << static_cast<std::underlying_type<CarColor>::type>(c);
  cout << "\nColor: " << static_cast<std::underlying_type<BikeColor>::type>(d);
  return 0;
}
