#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <vector>
#include <iomanip>

/*
TODO:
Funktioner/operatorer som inte ska modifera objektet ska vara const


Ska inte ha referens till primitiva datatyper (char, int, double tex)
om det inte behövs (Tar mer minne och kraft att göra en referens än en
kopia) (void set_voltage(double const& volts); ) *

5-4

// Ni bör tömma vektorn på pekare efter ni deletat det de pekar på. *

Om ni får ett exception ska programmet inte krascha utan ni ska fånga det och sen avsluta programmet korrekt.*

 */

class Connection {
public:
  Connection() = default; //?
  //~Connection() = default; //??
  double get_voltage() const;
  void set_voltage(double const volts);
  double Voltage{};
private:

};

class Component{
public:
  Component(std::string const name, Connection &Connection1, Connection &Connection2);
  virtual ~Component() = default;
  virtual void tick(double tickRate) = 0;
  virtual double voltage_diff() const;
  std::string get_name() const;
  virtual double get_current() const = 0;
private:
  std::string na;
protected:
  Connection& n;
  Connection& p;
};

class Battery: public Component {
public:
  Battery(std::string const name, double const Voltage, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
  double voltage_diff() const;
  double get_current() const;
private:
  double V;
};


class Resistor: public Component {
public:
  Resistor(std::string const name, double const Resistance, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
  double get_current() const;
private:
  double R;
};

class Capacitor: public Component {
public:
  Capacitor(std::string const name, double Capacitance, Connection &Connection1, Connection &Connection2);
  void tick(double tickRate) override;
  double get_current() const;
private:
  double F;
  double CH;
};

void simulate(std::vector<Component*> & net, int iterations, int rows, double tickRate);

#endif
