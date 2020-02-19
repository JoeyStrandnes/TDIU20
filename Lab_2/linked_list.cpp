#include "linked_list.h"

LL::LL() : first{nullptr}, last{nullptr} {
    first = new Element {-1, nullptr, nullptr};
    last = new Element {-1, nullptr, first};
    first->next = last;

}

LL::LL(std::initializer_list<int> elements) : first{nullptr}, last{nullptr} {
  first = new Element {-1, nullptr, nullptr};
  last = new Element {-1, nullptr, first};
  first->next = last;

  for (size_t i=0; i<elements.size(); i++) {
    insert(*(elements.begin()+i));
  }
} //GODTYCKLIG
LL::LL(LL const& rhs): first{nullptr}, last{nullptr} {
  first = new Element {-1, nullptr, nullptr};
  last = new Element {-1, nullptr, first};
  first->next = last;

  for (int i=1; i<=rhs.sizeOf(); i++) {
    insert(rhs.indexCheck(i));
  }
} //COPY

LL::LL(LL && rhs): first{rhs.first}, last{rhs.last} {
  rhs.first = new Element {-1, nullptr, nullptr};
  rhs.last = new Element {-1, nullptr, first};
  rhs.first->next = rhs.last;
} //MOVE //ÄR KANSKE RÄTT?

//LL& operator=(LL && rhs) //MÅSTE SKAPAS

LL::~LL() {
  int size = sizeOf();
  for (int i=0; i<size; i++){
    removeElement(1);
  }
  delete first;
  delete last;
} //DESTRCUT

int LL::sizeOf() const {
  Element* placeHolder = first;
  int numberOfElements{};
  while (placeHolder->next != last) {
    numberOfElements++;
    placeHolder = placeHolder->next;
  }
  return numberOfElements;
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

void LL::removeElement(int const i) {
  Element* placeHolder = indexFind(i);

  placeHolder->prev->next = placeHolder->next;
  placeHolder->next->prev = placeHolder->prev;
  delete placeHolder;
  placeHolder = nullptr;

}

void LL::insert(int const i) {
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

std::ostream& operator<<(std::ostream & lhs, LL const& rhs) {
  for (int i=1; i<=rhs.sizeOf(); i++) {
    if (i == rhs.sizeOf()) {
      lhs << rhs.indexCheck(i);
    } else {
      lhs << rhs.indexCheck(i) << " ";
    }
  }
  return lhs;
}

LL::Element::Element(int value, Element* next_el, Element* prev_el): data{value}, next{next_el}, prev{prev_el}
{

}
