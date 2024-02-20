#include "../include/state.h"

State::State(int state) {
  this->state = state;
}

int State::getState() {
  return this->state;
}

int State::getState() const {
  return this->state;
}

void State::setState(int state) {
  this->state = state;
}

std::string State::print() const {
  if(this->state == 0) {
    return " ";
  } else {
    return "X";
  }
}

std::ostream& operator<<(std::ostream& os, const State &s) {
  os << s.print();
  return os;
}

