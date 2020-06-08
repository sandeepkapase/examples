#include <iostream>

using namespace std;
//// Third party library START
class Vehicle {
public:
  virtual void printVehicle() = 0;
};

class Car: public Vehicle {
 public:
   void printVehicle() {
     cout << endl << "I am car" ;
   }
 };

class Bus: public Vehicle {
 public:
   void printVehicle() {
     cout << endl << "I am Bus" ;
   }
};
//// Third party library END

// Client using library
class Client {
private:
  Vehicle *vehPtr;

public:
  Client(int type) {
    if (type==0) {
      vehPtr = new Car();
    } else if (type==1)
      vehPtr = new Bus();
  }

  Vehicle * getVehicle() {
    return vehPtr;
  }

};

/* Here, if third party library adds new vehicle type, client need to
   update/changes its library also. This can be avoided by factory method.
 */
int main() {
  Client *cl1= new Client(0);
  Vehicle *vh1 = cl1->getVehicle();
  vh1->printVehicle();

  Client *cl2= new Client(1);
  Vehicle *vh2 = cl2->getVehicle();
  vh2->printVehicle();
}
