#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "component.h"

using namespace std;

/*
int main(int argc, char *argv[]) {

}
*/
TEST_CASE("FIRST TEST"){
  Connection p, n, b;
  vector<Component*> net;
  net.push_back(new Battery("Bat1", 12.0, p, n));
  net.push_back(new Resistor("R1", 5.0, p, b));
  net.push_back(new Resistor("R2", 10.0, b, n));
  //net.push_back(new Capacitor("C1", 1.0, p, n));
  simulate(net, 1, 1, 0.1);

  CHECK(p.Voltage == 12.0);

}
