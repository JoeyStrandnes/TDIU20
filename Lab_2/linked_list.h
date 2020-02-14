#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <assert.h>

class LL {
class Element;

public:

  LL();
  void insert(int const i);
  void removeElement(int const i);
  int indexCheck(int const i) const;

private:
  Element* indexFind(int const i) const;

class Element{

public:
  Element(int value, Element* next_el, Element* prev_el);
  int data{};
  Element* next;
  Element* prev;

};

Element* first;
Element* last;

};



#endif
