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
#include <cmath>

class Time {

public:

  Time(int HH, int MM, int SS);
  Time(std::string TS);
  bool is_am();
  std::string to_string(bool AM_PM=false) const;
  Time operator+ (int const n);
  Time operator- (int const n);
  Time();
  int hour();
  int minute();
  int second();

private:
  int Hour;
  int Minute;
  int Second;


};

std::ostream& operator<<(std::ostream & lhs, Time const& rhs);

#endif
