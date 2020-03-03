#include "component.h"

using namespace std;

Component::Component(std::string name, Connection &Conn1, Connection &Conn2):
na{name}, n{Conn1}, p{Conn2} {

}

Battery::Battery(std::string name, double Voltage, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), V{Voltage}{
  Connection1.Voltage = V;
  Connection2.Voltage += 0.0; //Gör serie-koppling av batterier möjligt
}

Resistor::Resistor(std::string name, double Resistance, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), R{Resistance}{

}

Capacitor::Capacitor(std::string name, double Capacitance, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), C{Capacitance}{

}


void Battery::tick(double tickRate) {
  std::cout << "Bajs" << '\n';
}

void Resistor::tick(double tickRate) {
  double tmp;
  if ((*this).Connection1.Voltage > (*this).Connection2.Voltage) {
    tmp = (*this).Connection1.Voltage  - (*this).Connection2.Voltage;
  }
  else {
    tmp = (*this).Connection2.Voltage  - (*this).Connection1.Voltage;
    (*this).Connection1.Voltage = (tmp/(*this).Resistance) * tickRate;
  }

}

void Capacitor::tick(double tickRate) {

}

void simulate(vector<Component*> net, int iterations, int rows, double tickRate) {
  for (int i = 0; i < iterations; i++) {
    for(Component* e : net ){
      e->tick(tickRate);
    }
    // Circuit Sim
  }
}
