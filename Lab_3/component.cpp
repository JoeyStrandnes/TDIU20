#include "component.h"

using namespace std;


Component::Component(std::string const name, Connection &Connection1, Connection &Connection2):
na{name}, n{Connection1}, p{Connection2} {

}

Battery::Battery(std::string const name, double const Voltage, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), V{Voltage}{
   //Gör serie-koppling av batterier möjligt
}

Resistor::Resistor(std::string const name, double const Resistance, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), R{Resistance}{

}

Capacitor::Capacitor(std::string const name, double Capacitance, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), F{Capacitance}, CH{0.0}{

}

double Connection::get_voltage() const {
  return Voltage;
}

void Connection::set_voltage(double const volts) {
  Voltage = volts;
}

string Component::get_name() const {
  return na;
}

double Component::voltage_diff() const {
  double volt{};
  if(p.get_voltage() >= n.get_voltage()) {
        volt = p.get_voltage() - n.get_voltage();
    }
    else {
        volt = n.get_voltage() - p.get_voltage();
    }
  return volt;
}

double Battery::voltage_diff() const{
  return V;
}

double Battery::get_current() const{
  return 0.0;
}

double Resistor::get_current() const{
  double current{};
  current = voltage_diff()/R;
  return current;
}

double Capacitor::get_current() const {
  double current{};
  current = F*(voltage_diff()-CH);
  return current;
}


void Battery::tick(double tickRate) {
  p.set_voltage(V);
  n.set_voltage(0.0 * tickRate); //??? <3
}

void Resistor::tick(double tickRate) {
  double tmp;
  tmp = ((p.get_voltage() - n.get_voltage())/R)* tickRate;
  p.set_voltage(p.get_voltage() -tmp);
  n.set_voltage(n.get_voltage() +tmp);

}

void Capacitor::tick(double tickRate) {
  double tmp;
  if(p.get_voltage() >= n.get_voltage()) {
    tmp = F*((voltage_diff()-CH)*tickRate);
    CH = CH + tmp;
    p.set_voltage(p.get_voltage() -tmp);
    n.set_voltage(n.get_voltage() +tmp);
  }
  else {
    tmp = F*((voltage_diff()-CH)*tickRate);
    CH = CH + tmp;
    p.set_voltage(p.get_voltage() +tmp);
    n.set_voltage(n.get_voltage() -tmp);
  }

}

void simulate(vector<Component*> & net, int iterations, int rows, double tickRate) {

  for (size_t k = 0; k < net.size(); k++) {
    cout << setw(14) << net[k]->get_name();
  }
  cout<<endl;
  for (size_t k = 0; k < net.size(); k++) {
    cout << setw(7) << "Volt:" << setw(7) << "Curr:";
  }
  cout<<endl;


  for(int r = 0; r < rows; r++){
      for (int i = 0; i < iterations/rows; i++) {
        for(Component* e : net ){
            e->tick(tickRate);
        }
      }

      for(Component* e : net ){
        cout << setw(7) << setprecision(2) << fixed << e->voltage_diff() << setw(7) << setprecision(2)<< e->get_current();
      }
      cout<<endl;

  }

  for (size_t i=0; i<net.size(); i++) {
    delete net.at(i);
  }
  net.clear();
  cout<<endl;
}
