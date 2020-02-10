#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Time.h"

using namespace std;

TEST_CASE ("Default constructor")
{
    Time t;

    CHECK(t.hour() == 0);
    CHECK(t.minute() == 0);
    CHECK(t.second() == 0);
}


TEST_CASE ( "Constructor with numeric arguments" )
{
    Time t{12,13,14};
    CHECK(t.hour() == 12);
    CHECK(t.minute() == 13);
    CHECK(t.second() == 14);
}

TEST_CASE ("Constructor with faulty argument")
{
    CHECK_THROWS( Time{41,0,0} );
    CHECK_THROWS( Time{0,99,0} );
    CHECK_THROWS( Time{0,0,99} );
}

TEST_CASE ("String constructor")
{
    Time t{"12:23:12"};
    CHECK(t.hour() == 12);
    CHECK(t.minute() == 23);
    CHECK(t.second() == 12);

    SECTION ("Throws as well")
    {
        CHECK_THROWS( Time{"02:11:74"} );
    }

}

TEST_CASE ("am or pm")
{
    Time t{12,12,31};
    CHECK_FALSE(t.is_am());
    Time t2{1,2,3};
    CHECK(t2.is_am());
}


TEST_CASE ("Convert to string" )
{
    CHECK( Time{12,12,12}.to_string()     ==    "12:12:12" );
    CHECK( Time{12, 1, 2}.to_string()     ==    "12:01:02" );
    CHECK( Time{14,33,12}.to_string(true) == "02:33:12 pm" );
}

TEST_CASE ("Conversion to string" )
{
    CHECK( string(Time{2,4,1}) == "02:04:01" );
}



TEST_CASE ("Output operator" )
{
    stringstream ss;
    SECTION("Simple output")
    {
        ss << Time{2,5,1};
        CHECK(ss.str() == "02:05:01");
    }

    SECTION("Chained output")
    {
        ss << Time{23,10,32} << "---";
        CHECK(ss.str() == "23:10:32---");
    }


    SECTION("Const time")
    {
        Time const t{23,23,23};
        ss << t;
        CHECK(ss.str() == "23:23:23");
    }

}

//TODO: Ta bort utkommenterad kod. *

TEST_CASE ("Custom TEST")
{
//TEST FOR + OPERATOR
  Time T2{0,0,0};
  Time Ti {12, 0, 0};


SECTION("+ OPERATOR"){
    Ti = (Ti+3600*24)+30;
    CHECK( Ti.hour() == 12);
    CHECK( Ti.minute() == 0);
    CHECK( Ti.second() == 30);

}

//TODO: Ni testar inte fallet då hela tiden ska gå över från t.ex. 00:00:00 till 23:59:59*

//TEST FOR - OPERATOR
SECTION("- OPERATOR"){
  Ti = {23, 55, 0};
  Ti = Ti - 125;

  CHECK( Ti.hour() == 23);
  CHECK( Ti.minute() == 52);
  CHECK( Ti.second() == 55);

}

SECTION("- OPERATOR LARGE"){
  Ti = {23, 55, 0};
  Ti = Ti - 86400*10;

  CHECK( Ti.hour() == 23);
  CHECK( Ti.minute() == 55);
  CHECK( Ti.second() == 0);

}

SECTION("- OPERATOR CROSSOVER"){
  Ti = {0, 0, 0};
  Ti = Ti - 1;

  CHECK( Ti.hour() == 23);
  CHECK( Ti.minute() == 59);
  CHECK( Ti.second() == 59);

}

//TODO: Ni testar inte att funkionaliteten stämmer för prefix för både ++ och --. *
//Hint: testa t.ex. (++t).to_string() etc..

SECTION("++ pre OPERATOR"){
  Ti = {23, 59, 59};

  CHECK((++Ti).to_string() == "00:00:00");

  CHECK( Ti.hour() == 0);
  CHECK( Ti.minute() == 0);
  CHECK( Ti.second() == 0);
}

SECTION("-- pre OPERATOR"){
  Ti = {00, 00, 00};
  --Ti;

  CHECK( Ti.hour() == 23);
  CHECK( Ti.minute() == 59);
  CHECK( Ti.second() == 59);

}

SECTION("++ post OPERATOR"){

    Ti = {23, 59, 59};
    T2 = Ti++;

    CHECK( T2.hour() == 23);
    CHECK( T2.minute() == 59);
    CHECK( T2.second() == 59);

    CHECK( Ti.hour() == 0);
    CHECK( Ti.minute() == 0);
    CHECK( Ti.second() == 0);

}


SECTION("-- post OPERATOR"){
  Ti = {0, 0, 0};
  T2=Ti--;

  CHECK( T2.hour() == 0);
  CHECK( T2.minute() == 0);
  CHECK( T2.second() == 0);

  CHECK( Ti.hour() == 23);
  CHECK( Ti.minute() == 59);
  CHECK( Ti.second() == 59);

}

//TODO: Alla operatorer ska testas i fallet då de returnerar true samt false
//för att se så att de faktiskt kan göra det. *

//Kommentar: Eftersom operatorerna returnerar en bool behöver ni inte jämföra med
//true eller false. Detta komemer evalueras till till exempel true == true osv..
//Använd CHECK_FALSE för att kolla motsatsen. *
SECTION("== OPERATOR"){
  Ti = {0, 0, 0};
  Time Tii{0, 0, 0};
  Time wrong{1,1,1};

  CHECK(Ti == Tii);
  CHECK_FALSE(Ti == wrong);
}

SECTION("< > OPERATOR"){
  Ti = {12, 30, 10};
  Time Tii{11, 23, 57};

  CHECK((Tii < Ti)==true);
  CHECK_FALSE(Tii > Ti);

}

SECTION("!= OPERATOR"){
  Ti = {12, 30, 10};
  Time Tii{11, 23, 57};
  Time wrong{11,23,57};

  CHECK(Tii != Ti);
  CHECK_FALSE(Tii != wrong);

}

SECTION("<= >= OPERATOR"){
  Ti = {12, 30, 10};
  Time Tii{11, 23, 57};

  CHECK(Tii <= Ti);
  CHECK_FALSE(Tii >= Ti);

}

//TODO: Chained input ska även testas.*

SECTION("Inmatning"){

    stringstream test;

    test << "23:10:05" <<" "<< "23:10:10";
    test >> Ti >> T2;

    CHECK(Ti.to_string() == "23:10:05");
    CHECK_FALSE(test.fail());

    CHECK(T2.to_string() == "23:10:10");
    CHECK_FALSE(test.fail());

}

SECTION("Inmatning with fail"){

    Time T2{12,13,5};
    Time Ti {13, 4, 2};

    stringstream test;

    test << "23:10:05" <<" "<< "60:10:10";
    test >> Ti >> T2;
    CHECK(test.fail());

    CHECK(Ti.to_string() == "23:10:05");
    CHECK(T2.to_string() == "12:13:05");

}

}

#if 0
#endif
