#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <assert.h>

class LL {
class Element;

public:

  LL();
  LL(std::initializer_list<int> elements); //GODTYCKLIG
  LL(LL const& rhs); //COPY
  LL(LL && rhs); //MOVE
  LL& operator=(LL const& rhs); //COPY
  LL& operator=(LL && rhs); //MOVE
  bool operator==(LL const& rhs) const;
  ~LL(); //DESTRUCT
  void insert(int const i);
  void removeElement(int const i);
  int indexCheck(int const i) const;
  int sizeOf() const;

  friend std::ostream& operator<<(std::ostream & lhs, LL const& rhs);

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
