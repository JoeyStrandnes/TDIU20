#include "component.h"

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
