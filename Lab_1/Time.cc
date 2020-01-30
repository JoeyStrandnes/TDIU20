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

Time::Time(string TS): Hour{}, Minute{}, Second{}
  {
    string TMP{};
    int HH{};
    int MM{};
    int SS{};

    stringstream buffer;
    buffer << TS;
    getline(buffer, TMP, ':');
    HH = stoi(TMP);
    //buffer.ignore(1);

    getline(buffer, TMP, ':');
    MM = stoi(TMP);
    //buffer.ignore(1);

    getline(buffer, TMP, ':');
    SS = stoi(TMP);
    //buffer.ignore(1);


    try{
      if(HH > 24 || MM > 60 || SS > 60){
        throw 1;
      }
    }
    catch(exception& e){
      cout << "Incorrect Input" << '\n';
    }

    Hour=HH;
    Minute=MM;
    Second=SS;
}

bool Time::is_am(){

if (Hour < 12){
  return true;
}

  return false;
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

string Time::to_string(bool AM_PM) const{

  stringstream buffer;
  string TMP;

  int TMP_H{Hour};

  if (AM_PM == true){
    if (Hour >= 12) {
      if (Hour > 12) {
        TMP_H += -12;
      }
      buffer << setw(2) << setfill('0') << TMP_H << ':' << setw(2) << setfill('0') << Minute << ':' << setw(2) << setfill('0') << Second << " pm";
    } else {
      buffer << setw(2) << setfill('0') << TMP_H << ':' << setw(2) << setfill('0') << Minute << ':' << setw(2) << setfill('0') << Second << " am";
    }
  } else {
    buffer << setw(2) << setfill('0') << TMP_H << ':' << setw(2) << setfill('0') << Minute << ':' << setw(2) << setfill('0') << Second;
  }
  TMP=buffer.str();
  return TMP;

}

ostream& operator<<(ostream & lhs, Time const& rhs) {
  lhs << rhs.to_string();
  return lhs;
}

Time Time::operator+ (int const n){

  int K = n % 24;
  Time TMP_TIME{*this};
  int TMP;

  TMP = ((Hour*3600)+(Minute*60)+(Second)+K);

  TMP_TIME.Hour = TMP/3600;
  if(TMP_TIME.Hour == 24){TMP_TIME.Hour = 0;};

  TMP_TIME.Minute = (TMP%3600) / 60;

  TMP_TIME.Second = (TMP % 3600)%60 ;

  //std::cout << TMP_TIME.Hour << '\n' << TMP_TIME.Minute << '\n' << TMP_TIME.Second << '\n';


  return TMP_TIME;

}

Time Time::operator- (int const n){

  int K =  n % 24;
  Time TMP_TIME{*this};
  int TMP;

  TMP = (Hour*3600)+(Minute*60)+(Second)-K);

  TMP_TIME.Hour = TMP/3600;
  if(TMP_TIME.Hour < 0){TMP_TIME.Hour -= 24;};


  TMP_TIME.Minute = (TMP%3600) / 60;
//  if(TMP_TIME.Hour < 0){TMP_TIME.Hour -= 24;};

  TMP_TIME.Second = (TMP % 3600)%60 ;

  //std::cout << TMP_TIME.Hour << '\n' << TMP_TIME.Minute << '\n' << TMP_TIME.Second << '\n';


  return TMP_TIME;

}
