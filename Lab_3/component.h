#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <vector>
#include <iomanip>

class Connection {
public:
  Connection() = default; //?
  //~Connection() = default; //??
  double get_voltage();
  void set_voltage(double const& volts);
  double Voltage{};
private:

};

class Component{
public:
  Component(std::string name, Connection &Connection1, Connection &Connection2);
  virtual ~Component() = default;
  virtual void tick(double tickRate) = 0;
  virtual double voltage_diff();
  std::string get_name();
  virtual double get_current() = 0;
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
  double voltage_diff();
  double get_current();
private:
  double V;
};


class Resistor: public Component {
public:
  Resistor(std::string name, double Resistance, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
  double get_current();
private:
  double R;
};

class Capacitor: public Component {
public:
  Capacitor(std::string name, double Capacitance, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
  double get_current();
private:
  double F;
  double CH;
};

void simulate(std::vector<Component*> net, int iterations, int rows, double tickRate);

#endif
