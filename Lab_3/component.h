#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <vector>

class Connection {
public:
  Connection() = default; //?
  double Voltage{};
private:

};

class Component{
public:
  Component(std::string name, Connection &Conn1, Connection &Conn2);
private:
  std::string na;
  Connection& n;
  Connection& p;
};

class Battery: public Component {
public:
  Battery(std::string name, double Voltage, Connection &Connection1, Connection &Connection2);
private:
  double V;
};


class Resistor: public Component {
public:
  Resistor(std::string name, double Resistance, Connection &Connection1, Connection &Connection2);
private:
  double R;
};

class Capacitor: public Component {
public:
  Capacitor(std::string name, double Capacitance, Connection &Connection1, Connection &Connection2);
private:
  double C;
};


#endif
