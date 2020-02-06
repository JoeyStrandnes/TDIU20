#ifndef LINKED_LIST
#define LINKED_LIST

class LL {


public:

  void insert(int const i);


private:


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
