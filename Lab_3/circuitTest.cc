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
  /* CIRCUIT 1
  Connection a, b, q1, q2;
  vector<Component*> net;
  net.push_back(new Battery("Bat1", 24.0, a, b));
  net.push_back(new Resistor("R1", 6.0, a, q1));
  net.push_back(new Resistor("R2", 4.0, q1, q2));
  net.push_back(new Resistor("R2", 8.0, q2, b));
  net.push_back(new Resistor("R2", 12.0, q1, b));
  //net.push_back(new Capacitor("C1", 1.0, p, n));
  simulate(net, 20000, 10, 0.01);

  */

  Connection p, n, l, r;
  vector<Component*> net;
  net.push_back(new Battery("Bat1", 24.0, p, n));
  net.push_back(new Resistor("R1", 150.0, p, l));
  net.push_back(new Resistor("R2", 50.0, p, r));
  net.push_back(new Capacitor("C1", 1.0, l, r));
  net.push_back(new Resistor("R3", 300.0, l, n));
  net.push_back(new Capacitor("C2", 0.75, r, n));
  simulate(net, 20000, 10, 0.01);

}
