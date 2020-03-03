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

  for (int i=rhs.sizeOf(); i>0; i--) { //KOLLA NULLPTR
    insert(rhs.indexCheck(i));
  }
} //COPY

bool LL::operator==(LL const& rhs) const{
  if (sizeOf() == rhs.sizeOf()) {
    int size = sizeOf();
    for(int i=1; i<=size; i++) {
      if(indexCheck(i) != rhs.indexCheck(i)) {
        return false;
      }
    }
    return true;
  }
  return false;
}

//TODO: Det ser ut att bli minnesläckor ifall *this redan har element.
//Se även till så att fallet l = l fungerar efter detta är åtgärdat. * TROR JAG

//TODO: Här kallar ni på sizeof varje varv i loopen. Varje insättning
//kommer därför kräva ett helt varv genom rhs. * LÖGN?
LL& LL::operator=(LL const& rhs) {
  if(!((*this) == rhs)) {
    for(int i=sizeOf(); i>0; i--) {
      removeElement(1);
    }
    for (int i=rhs.sizeOf(); i>0; i--) {
      insert(rhs.indexCheck(i));
    }
  }
  return *this;
} //COPY OPERATOR

LL::LL(LL && rhs): first{rhs.first}, last{rhs.last} {
  rhs.first = new Element {-1, nullptr, nullptr};
  rhs.last = new Element {-1, nullptr, first};
  rhs.first->next = rhs.last;
} //MOVE

LL& LL::operator=(LL && rhs) {
  for(int i = sizeOf(); i>0; i--) {
    removeElement(1);
  }
  first = std::__exchange(rhs.first, first);
  last = std::__exchange(rhs.last, last);
  return *this;
} //MOVE OPERATOR

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

//Kommentar: Snyggt löst med denna hjälpfunktion!
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

//TODO: Ta bort onödig/utkommenterad kod. *
void LL::insert(int const i) {
  Element* placeHolder = first;
  while (placeHolder->next->data < i && placeHolder->next != last) {
    placeHolder = placeHolder->next;
  }
  placeHolder = placeHolder->next;
  placeHolder->prev->next = new Element {i, placeHolder, placeHolder->prev};
  placeHolder->prev = placeHolder->prev->next;
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
