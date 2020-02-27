#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "component.h"

using namespace std;


TEST_CASE("FIRST TEST"){
  Connection p, n;
  vector<Component*> net;
  net.push_back(new Battery("Bat1", 12.0, p, n));
  net.push_back(new Resistor("R1", 5.0, p, n));
  net.push_back(new Capacitor("C1", 1.0, p, n));

  CHECK(p.Voltage == 12.0);

}
