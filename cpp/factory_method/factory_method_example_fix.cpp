#include <iostream>
enum VehicleType {VEH_CAR, VEH_BUS, VEH_RICKSHAW };

using namespace std;

//// Third party library
class Vehicle {
public:
  virtual void printVehicle() = 0;
  static Vehicle * Create(VehicleType type);
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
     cout << endl << "I am bus" ;
   }
 };


class Rickshaw: public Vehicle {
public:
  void printVehicle() {
    cout << endl << "I am Rickshaw" ;
   }
};

Vehicle * Vehicle::Create(VehicleType type) {
    if (type == VEH_CAR)
      return new Car();
    else if (type == VEH_BUS)
      return new Bus();
    else if (type == VEH_RICKSHAW)
      return new Rickshaw();
    else return NULL;
}

// Client using library
class Client {
private:
  Vehicle *vehPtr;

public:
  Client(VehicleType type) {
    vehPtr = Vehicle::Create(type);
  }
  ~Client() {
    if (vehPtr) delete vehPtr ;
    cout << endl << "Desctructor called." ; 
  }

  Vehicle * getVehicle() {
    return vehPtr;
  }

};

/* Here, Even if third type library add more vehicle to their library,
   client don't need to change it's library. */
int main() {
  {
  Client *cl1= new Client(VEH_CAR);
  Vehicle *vh1 = cl1->getVehicle();
  vh1->printVehicle();
  }

  Client *cl2= new Client(VEH_BUS);
  Vehicle *vh2 = cl2->getVehicle();
  vh2->printVehicle();

  Client *cl3= new Client(VEH_RICKSHAW);
  Vehicle *vh3 = cl3->getVehicle();
  vh3->printVehicle();
}
