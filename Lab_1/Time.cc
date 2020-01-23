// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"

using namespace std;

Time::Time(int HH, int MM, int SS): Hour{HH}, Minute{MM}, Second{SS}
{
  try{
    if(HH > 24 || MM > 60 || SS > 60){
      throw 1;
    }
  }
  catch(exception& e){
    cout << "Incorrect Input" << '\n';
  }

}

Time::Time(): Hour{}, Minute{}, Second{}
{}

Time::Time(string TS): timeString{TS}
  {
    string TMP{};
    int HH{};
    int MM{};
    int SS{};

    stringstream buffer;
    buffer >> timeString;
    getline(buffer, TMP, ':');
    HH = stoi(TMP);
    buffer.ignore(1);

    getline(buffer, TMP, ':');
    MM = stoi(TMP);
    buffer.ignore(1);

    getline(buffer, TMP, ':');
    SS = stoi(TMP);
    buffer.ignore(1);


    try{
      if(HH > 24 || MM > 60 || SS > 60){
        throw 1;
      }
    }
    catch(exception& e){
      cout << "Incorrect Input" << '\n';
    }
}


int Time::hour(){

  return Hour;
}

int Time::minute(){

  return Minute;
}
int Time::second(){

  return Second;
}
