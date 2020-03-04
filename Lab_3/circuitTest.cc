#include <string>
#include <iostream>
#include <sstream>

#include "component.h"

using namespace std;


int main(int argc, char *argv[]) {
  if (argc != 5) {
    throw invalid_argument{"INVALID ARGUMENT"};
  }

  int iterations{};
  int rows{};
  double tickRate{};
  double battVoltage{};

  iterations = std::stoi(argv[1]);
  rows = std::stoi(argv[2]);
  tickRate = std::stod(argv[3]);
  battVoltage = std::stod(argv[4]);
  if (iterations <= 0 || rows <= 0 || tickRate <= 0 || battVoltage <= 0) {
      throw out_of_range{"NEGATIVE INPUT"};
  }
  std::cout << "Krets 1:" << '\n';
  Connection a, b, q1, q2;
  vector<Component*> net;
  net.push_back(new Battery("Bat1", battVoltage, a, b));
  net.push_back(new Resistor("R1", 6.0, a, q1));
  net.push_back(new Resistor("R2", 4.0, q1, q2));
  net.push_back(new Resistor("R3", 8.0, q2, b));
  net.push_back(new Resistor("R4", 12.0, q1, b));
  simulate(net, iterations, rows, tickRate);

  std::cout << "Krets 2:" << '\n';
  Connection x, y, z1, z2;
  vector<Component*> net2;
  net2.push_back(new Battery("Bat1", battVoltage, x, y));
  net2.push_back(new Resistor("R1", 150.0, x, z1));
  net2.push_back(new Resistor("R2", 50.0, x, z2));
  net2.push_back(new Resistor("R3", 100.0, z1, z2));
  net2.push_back(new Resistor("R4", 300.0, z1, y));
  net2.push_back(new Resistor("R5", 250.0, z2, y));
  simulate(net2, iterations, rows, tickRate);

  std::cout << "Krets 3:" << '\n';
  Connection p, n, l, r;
  vector<Component*> net3;
  net3.push_back(new Battery("Bat1", battVoltage, p, n));
  net3.push_back(new Resistor("R1", 150.0, p, l));
  net3.push_back(new Resistor("R2", 50.0, p, r));
  net3.push_back(new Capacitor("C3", 1.0, l, r));
  net3.push_back(new Resistor("R4", 300.0, l, n));
  net3.push_back(new Capacitor("C5", 0.75, r, n));
  simulate(net3, iterations, rows, tickRate);

}
