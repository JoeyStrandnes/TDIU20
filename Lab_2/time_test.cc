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


}



#if 0

#endif
