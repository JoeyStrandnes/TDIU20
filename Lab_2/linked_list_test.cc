#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "linked_list.h"

using namespace std;


TEST_CASE("FIRST TEST"){

  LL List;
  stringstream ss;
SECTION ("INSERT") {
  List.insert(10);
  List.insert(4);
  List.insert(9);
}

//Kommentar: C++ är 0-indexerat. Ada <3
SECTION ("INDEX CHECK") {
  List.insert(10);
  List.insert(4);
  List.insert(9);
  CHECK(List.indexCheck(1) == 4);
  CHECK(List.indexCheck(2) == 9);
  CHECK(List.indexCheck(3) == 10);
  CHECK_THROWS(List.indexCheck(4));
  CHECK(List.sizeOf()==3);

  List.removeElement(2);
  CHECK(List.indexCheck(2) == 10);
  CHECK(List.indexCheck(1) == 4);
  CHECK_THROWS(List.indexCheck(3));
  CHECK(List.sizeOf()==2);
}

SECTION ("INTIALIZER LIST") {
  LL List2{1,7,4,20,10};
  CHECK(List2.indexCheck(1) == 1);
  CHECK(List2.indexCheck(2) == 4);
  CHECK(List2.indexCheck(3) == 7);
  CHECK(List2.indexCheck(4) == 10);
  CHECK(List2.indexCheck(5) == 20);
}

SECTION ("TO STREAM") {
  LL List2{1,7,4,20,10};
  ss << List2;
  CHECK(ss.str() == "1 4 7 10 20");
}

//TODO: Ni testar inte fallet då en lista redan har värden och sedan
//blir tilldelad en annan lista. Se TODO i .cc *
SECTION ("COPY") {
  LL List2{1,7,4,20,10};
  LL List3{List2};
  ss.str("");
  ss << List3;
  CHECK(ss.str() == "1 4 7 10 20");
  List3.removeElement(1);
  ss.str("");
  ss << List2;
  CHECK(ss.str() == "1 4 7 10 20");
  ss.str("");
  ss << List3;
  CHECK(ss.str() == "4 7 10 20");

  LL List4;
  List4 = List2;
  List4.removeElement(1);
  ss.str("");
  ss << List2;
  CHECK(ss.str() == "1 4 7 10 20");
  ss.str("");
  ss << List4;
  CHECK(ss.str() == "4 7 10 20");


  LL listOne{1,2,3};
  LL listTwo{4,5,6};
  LL listThree{4,5,6};
  listOne = listTwo;
  ss.str("");
  ss << listOne;
  CHECK(ss.str() == "4 5 6");
  listThree = listThree;
  ss.str("");
  ss << listThree;
  CHECK(ss.str() == "4 5 6");

}

//TODO: Samma som ovan (COPY). *
SECTION ("MOVE") {
  LL List2{1,7,4,20,10};
  LL List5{move(List2)};
  ss.str("");
  ss << List2;
  CHECK(ss.str() == "");
  ss.str("");
  ss << List5;
  CHECK(ss.str() == "1 4 7 10 20");

  LL List6{-1,3,5,7,9};
  LL List7{};
  List7 = move(List6);
  ss.str("");
  ss << List6;
  CHECK(ss.str() == "");
  ss.str("");
  ss << List7;
  CHECK(ss.str() == "-1 3 5 7 9");
<<<<<<< HEAD
=======

  LL listOne{1,2,3};
  LL listTwo{4,5,6};
  LL listThree{4,5,6};

  listOne = move(listTwo);
  ss.str("");
  ss << listOne;
  CHECK(ss.str() == "4 5 6");
  ss.str("");
  ss << listTwo;
  CHECK(ss.str() == "");
  listThree = listThree;
  ss.str("");
  ss << listThree;
  CHECK(ss.str() == "4 5 6");
>>>>>>> 1958f2a4b7dabf2c06c49323b15b6d50edccdbc8
}

}



#if 0

#endif
