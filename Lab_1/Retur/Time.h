// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H


#include <exception>
#include <iostream>
#include <sstream>
#include <iomanip>

//TODO: Inkludera endast paket som används i filen. *

//TODO: Alla funktioner som inte ska ändra på objektet ska deklareras const. *

class Time {

public:

  Time(const int HH, const int MM, const int SS);
  Time(const std::string TS);
  bool is_am() const;
  std::string to_string(bool const AM_PM=false) const;
  bool checkTime(int const& HH, int const& MM, int const& SS) const;

  //OPERATORER
  Time operator+ (int const n) const;
  Time operator- (int const n) const;
  Time& operator++();
  Time& operator--();
  Time operator++(int);
  Time operator--(int);
  bool operator==(Time const& rhs) const;
  bool operator<(Time const& rhs) const;
  bool operator>(Time const& rhs) const;
  bool operator!=(Time const& rhs) const;
  bool operator<=(Time const& rhs) const;
  bool operator>=(Time const& rhs) const;
  operator std::string() const;

  Time();
  int hour() const;
  int minute() const;
  int second() const;

  friend std::ostream& operator<<(std::ostream & lhs, Time const& rhs);
  friend std::istream& operator>>(std::istream & lhs, Time & rhs);

private:
  int Hour;
  int Minute;
  int Second;


};



#endif
