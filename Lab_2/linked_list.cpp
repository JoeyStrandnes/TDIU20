#include "linked_list.h"

LL::LL() : first{nullptr}, last{nullptr} {

}

LL::Element* LL::indexFind(int const i) const {
  Element* placeHolder = first;
  for (int k = 0; k < i; k++) {

    if (placeHolder->next == last) {
      throw "Out of bound";
    }

    placeHolder = placeHolder->next;
  }
  return placeHolder;
}

int LL::indexCheck(int const i) const{
  Element* placeHolder = indexFind(i);
  return placeHolder->data;
}


void removeElement(int const i) {
  Element* placeHolder = indexFind(i);

  

}

void LL::insert(int const i){
  /////SKA IN I KOSNTRUKTORN///////
  if (first==nullptr) {
    first = new Element {-1, nullptr, nullptr};
    last = new Element {-1, nullptr, first};
    first->next = last;
  }
  /////SKA IN I KOSNTRUKTORN///////
  Element* placeHolder = first;
  while (placeHolder->next->data < i && placeHolder->next != last) {
    placeHolder = placeHolder->next;
  }
  Element* tmp = placeHolder->next;
  placeHolder->next = new Element {i, tmp, placeHolder};
  tmp->prev = placeHolder->next;

  //delete tmp;
  //delete placeHolder;

  //tmp = nullptr;
  //placeHolder = nullptr;

}

LL::Element::Element(int value, Element* next_el, Element* prev_el): data{value}, next{next_el}, prev{prev_el}
{

}
