#include "../include/state.h"

State::State(int state) {
  this->state = state;
}

int State::getState() const {
  return this->state;
}

std::ostream& operator<<(std::ostream& os, const State &s) {
  os << s.print();
  return os;
}
