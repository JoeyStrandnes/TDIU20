#include "linked_list.h"

void LL::insert(int const i){
  if (first==nullptr) {
    first = new Element {-1, nullptr, nullptr};
    last = new Element {-1, nullptr, first};
    first->next = last;
  }

  Element* tmp = first->next;
  first->next = new Element {i, tmp, last->prev};
  last->prev = first->next;

}

LL::Element::Element(int value, Element* next_el, Element* prev_el): data{value}, next{next_el}, prev{prev_el}
{

}
