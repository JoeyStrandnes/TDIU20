#include <string>
#include <iostream>
#include <sstream>

#include "component.h"

using namespace std;


int main(int argc, char *argv[]) {
  int iterations{};
  int rows{};
  double tickRate{};
  double battVoltage{};

  try{

    if (argc != 5) {
      throw invalid_argument{"INVALID ARGUMENT"};
    }

    iterations = std::stoi(argv[1]);
    rows = std::stoi(argv[2]);
    tickRate = std::stod(argv[3]);
    battVoltage = std::stod(argv[4]);

    if (iterations <= 0 || rows <= 0 || tickRate <= 0 || battVoltage <= 0) {
        throw out_of_range{"NEGATIVE INPUT"};
    }
  }

  catch(...){
    cerr << "INVALID ARGUMENT" << '\n';
    return 1;
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
  net.push_back(new Battery("Bat1", battVoltage, x, y));
  net.push_back(new Resistor("R1", 150.0, x, z1));
  net.push_back(new Resistor("R2", 50.0, x, z2));
  net.push_back(new Resistor("R3", 100.0, z1, z2));
  net.push_back(new Resistor("R4", 300.0, z1, y));
  net.push_back(new Resistor("R5", 250.0, z2, y));
  simulate(net, iterations, rows, tickRate);

  std::cout << "Krets 3:" << '\n';
  Connection p, n, l, r;
  net.push_back(new Battery("Bat1", battVoltage, p, n));
  net.push_back(new Resistor("R1", 150.0, p, l));
  net.push_back(new Resistor("R2", 50.0, p, r));
  net.push_back(new Capacitor("C3", 1.0, l, r));
  net.push_back(new Resistor("R4", 300.0, l, n));
  net.push_back(new Capacitor("C5", 0.75, r, n));
  simulate(net, iterations, rows, tickRate);

}
