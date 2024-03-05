#include "../include/cell.h"
#include "../include/stateDead.h"

Cell::Cell() {
  this->state = new StateDead();
}

Cell::Cell(const State& state){
  *(this->state) = state; 
}

Cell::~Cell(void){}

const State& Cell::getState(void) const{
  return *(this->state);
}

const int Cell::getStateInt(void) const{
  return this->state->getState();
}

void Cell::setState(State& state){
  this->state = &state;
}

void Cell::setPosition(Position* position){
  this->position = position;
}

Position Cell::getPosition(void){
  return *(this->position);
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
  os << cell.getState();
  return os;
}