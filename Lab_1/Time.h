// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include <ostream>
#include <iomanip>

class Time {

public:

  Time(int HH, int MM, int SS);
  Time(std::string TS);
  bool is_am();
  std::string to_string(bool AM_PM=false) const;

  //OPERATORER
  Time operator+ (int const n);
  Time operator- (int const n);
  Time& operator++();
  Time& operator--();
  Time operator++(int);
  Time operator--(int);
  bool operator==(Time const& rhs);
  bool operator<(Time const& rhs);
  bool operator>(Time const& rhs);
  bool operator!=(Time const& rhs);
  bool operator<=(Time const& rhs);
  bool operator>=(Time const& rhs);
  operator std::string() const;

  Time();
  int hour();
  int minute();
  int second();

  friend std::ostream& operator<<(std::ostream & lhs, Time const& rhs);
  friend std::istream& operator>>(std::istream & lhs, Time & rhs);

private:
  int Hour;
  int Minute;
  int Second;


};



#endif
