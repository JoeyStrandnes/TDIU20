#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "linked_list.h"

using namespace std;


TEST_CASE("FIRST TEST"){

  LL List;

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

  LL List2{1,7,4,20,10};
  CHECK(List2.indexCheck(1) == 1);
  CHECK(List2.indexCheck(2) == 4);
  CHECK(List2.indexCheck(3) == 7);
  CHECK(List2.indexCheck(4) == 10);
  CHECK(List2.indexCheck(5) == 20);

  stringstream ss;
  ss << List2;
  CHECK(ss.str() == "1 4 7 10 20");

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

  LL List4 = List2;
  List4.removeElement(1);
  ss.str("");
  ss << List2;
  CHECK(ss.str() == "1 4 7 10 20");
  ss.str("");
  ss << List4;
  CHECK(ss.str() == "4 7 10 20");

  LL List5{move(List2)};
  ss.str("");
  ss << List2;
  CHECK(ss.str() == "");
  ss.str("");
  ss << List5;
  CHECK(ss.str() == "1 4 7 10 20");

}



#if 0

#endif
