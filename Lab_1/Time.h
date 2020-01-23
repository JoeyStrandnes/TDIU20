// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H

#include <string>
#include <exception>
#include <iostream>
#include <sstream>

class Time {

public:

  Time(int HH, int MM, int SS);
  Time(std::string TS);
  Time();
  int hour();
  int minute();
  int second();


private:

  int Hour;
  int Minute;
  int Second;
  std::string timeString;

};

#endif
