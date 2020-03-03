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
  virtual void tick(double tickRate) = 0;
private:
  std::string na;
protected:
  Connection& n;
  Connection& p;
};

class Battery: public Component {
public:
  Battery(std::string name, double Voltage, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
private:
  double V;
};


class Resistor: public Component {
public:
  Resistor(std::string name, double Resistance, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
private:
  double R;
};

class Capacitor: public Component {
public:
  Capacitor(std::string name, double Capacitance, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
private:
  double C;
};

void simulate(std::vector<Component*> net, int iterations, int rows, double tickRate);

#endif
